define execute-command
$(1)

endef

BUILDDIR = build

TOOLS = tools

SOURCES := $(wildcard src/*.c)
HEADERS := $(wildcard include/*.h)
TESTS := $(wildcard tests/*.c)
MOCKS := $(wildcard tests/mocks/*.c)

INCLUDES += -Iinclude -I

LIB = lib/launchpad_pro.a

OBJECTS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))
TEST_RUNS = $(addprefix $(BUILDDIR)/, $(addsuffix .run, $(basename $(TESTS))))

# output files
SYX = $(BUILDDIR)/polyboard.syx
ELF = $(BUILDDIR)/polyboard.elf
HEX = $(BUILDDIR)/polyboard.hex
HEXTOSYX = $(BUILDDIR)/hextosyx

# tools
HOST_GPP = g++
HOST_GCC = gcc
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CODE_STYLE = llvm

CFLAGS  = -Os -Wall -I.\
-D_STM32F103RBT6_  -D_STM3x_  -D_STM32x_ -mthumb -mcpu=cortex-m3 \
-fsigned-char  -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=6000000UL \
-DCMSIS -DUSE_GLOBAL_CONFIG -ffunction-sections -std=c99  -mlittle-endian \
$(INCLUDES) -o

LDSCRIPT = stm32_flash.ld

LDFLAGS += -T$(LDSCRIPT) -u _start -u _Minimum_Stack_Size  -mcpu=cortex-m3 -mthumb -specs=nano.specs -specs=nosys.specs -nostdlib -Wl,-static -N -nostartfiles -Wl,--gc-sections

all: test $(SYX)

# build the final sysex file from the ELF - run the simulator first
$(SYX): $(HEX) $(HEXTOSYX) 
	./$(HEXTOSYX) $(HEX) $(SYX)

# build the tool for conversion of ELF files to sysex, ready for upload to the unit
$(HEXTOSYX):
	$(HOST_GPP) -Ofast -std=c++0x -I./$(TOOLS)/libintelhex/include ./$(TOOLS)/libintelhex/src/intelhex.cc $(TOOLS)/hextosyx.cpp -o $(HEXTOSYX)

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

$(ELF): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(LIB)

DEPENDS := $(OBJECTS:.o=.d)

-include $(DEPENDS)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -MMD -o $@ $<

$(BUILDDIR)/tests/%.run: tests/%.c $(SOURCES) $(MOCKS)
	mkdir -p $(dir $@)
	$(HOST_GCC) -g3 -O0 -std=c99 -Iinclude $^ -o $@ -lcmocka

test: $(TEST_RUNS)
	@$(foreach test, $(TEST_RUNS), \
		$(call execute-command, $(test)))
	@echo "All tests completed"

fmt: $(SOURCES) $(HEADERS)
	clang-format --style=$(CODE_STYLE) -i $^
.PHONY: fmt

tidy: $(SOURCES) $(HEADERS)
	clang-tidy $^ -- -Iinclude
.PHONY: tidy

lint: $(SOURCES) $(HEADERS)
	clang-format --style=$(CODE_STYLE) -Werror --dry-run $^
.PHONY: lint

clean:
	rm -rf $(BUILDDIR)

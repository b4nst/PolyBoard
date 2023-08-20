#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "note.h"

static void test_is_note_in_scale(void **state) {
	assert_int_equal(is_note_in_scale(0, 0, MAJOR_SCALE), 1);
	assert_int_equal(is_note_in_scale(92, 0, MINOR_SCALE), 0);
	assert_int_equal(is_note_in_scale(0, 3, MAJOR_SCALE), 0);
	assert_int_equal(is_note_in_scale(95, 0, MINOR_SCALE), -1);
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_is_note_in_scale),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

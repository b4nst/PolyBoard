#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "surface.h"

static void test_index_to_surface_key_type(void **state) {
    (void) state; /* unused */

    assert_int_equal(index_to_surface_key_type(95), SURFACE_CTRL);
    assert_int_equal(index_to_surface_key_type(5), SURFACE_CTRL);
    assert_int_equal(index_to_surface_key_type(29), SURFACE_CTRL);
    assert_int_equal(index_to_surface_key_type(21), SURFACE_CTRL);
    assert_int_equal(index_to_surface_key_type(15), SURFACE_PAD);
    assert_int_equal(index_to_surface_key_type(36), SURFACE_PAD);
    assert_int_equal(index_to_surface_key_type(48), SURFACE_PAD);
}

static void test_index_to_note(void **state) {
    (void) state; /* unused */

    struct NoteParams params = {
	.root = 0,
	.octave = 5,
	.interval = 5,
    };
    unsigned char scale[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    assert_int_equal(index_to_note(11, &params, scale), 60);
    assert_int_equal(index_to_note(36, &params, scale), 75);
    assert_int_equal(index_to_note(55, &params, scale), 84);

    unsigned char scale2[8] = {0, 1, 2, 3, 32, 33, 34, 35};
    params.octave = 2;
    params.interval = 4;
    assert_int_equal(index_to_note(11, &params, scale2), 24);
    assert_int_equal(index_to_note(36, &params, scale2), 65);
    assert_int_equal(index_to_note(78, &params, scale2), 83);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_index_to_surface_key_type),
	cmocka_unit_test(test_index_to_note),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}


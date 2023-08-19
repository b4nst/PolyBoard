#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "surface.h"

/* A test case that does nothing and succeeds. */
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

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_index_to_surface_key_type),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "note.h"
#include "page.h"

static void test_change_page_scale_type(void **state) {
	(void) state; /* unused */

	const Page* page = get_page(get_current_page());
	assert_int_not_equal(page->scale_type, MINOR_SCALE);
	change_page_scale_type(MINOR_SCALE);
	assert_int_equal(page->scale_type, MINOR_SCALE);
}

static void test_change_page_key(void **state) {
	(void) state; /* unused */

	const Page* page = get_page(get_current_page());
	assert_int_not_equal(page->key, 3);
	change_page_key(3);
	assert_int_equal(page->key, 3);
}

static void test_change_page_octave(void **state) {
	(void) state; /* unused */

	const Page* page = get_page(get_current_page());
	assert_int_not_equal(page->octave, 3);
	change_page_octave(3);
	assert_int_equal(page->octave, 3);
	change_page_octave(11);
	assert_int_equal(page->octave, 3);
}

static void test_change_page(void **state) {
	(void) state; /* unused */

	const Page* page = get_page(get_current_page());

	assert_ptr_equal(page, change_page(8));
	assert_ptr_not_equal(page, change_page(1));
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_change_page_scale_type),
		cmocka_unit_test(test_change_page_key),
		cmocka_unit_test(test_change_page_octave),
		cmocka_unit_test(test_change_page),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

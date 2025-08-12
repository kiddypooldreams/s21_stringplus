#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_memchr_basic) {
    const char *str = "Hello, world!";
    int c = 'w';
    size_t n = strlen(str);
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr_null) {
    ck_assert_ptr_eq(s21_memchr(NULL, 'a', 5), S21_NULL);
}
END_TEST

START_TEST(test_s21_memchr_empty) {
    const char *str = "";
    ck_assert_ptr_eq(s21_memchr(str, 'a', 0), memchr(str, 'a', 0));
}
END_TEST

START_TEST(test_s21_memchr_not_found) {
    const char *str = "Hello, world!";
    ck_assert_ptr_eq(s21_memchr(str, 'z', strlen(str)), memchr(str, 'z', strlen(str)));
}
END_TEST

Suite *s21_memchr_suite(void) {
    Suite *s = suite_create("s21_memchr");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memchr_basic);
    tcase_add_test(tc_core, test_s21_memchr_null);
    tcase_add_test(tc_core, test_s21_memchr_empty);
    tcase_add_test(tc_core, test_s21_memchr_not_found);
    suite_add_tcase(s, tc_core);
    return s;
}

#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_memset_basic) {
    char str[20] = "Hello, world!";
    ck_assert_ptr_eq(s21_memset(str, 'A', 5), memset(str, 'A', 5));
    ck_assert_str_eq(str, "AAAAA, world!");
}
END_TEST

START_TEST(test_s21_memset_zero_n) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    char str[20] = "Hello";
    size_t i = 0;
    ck_assert_ptr_eq(s21_memset(str, 'A', i), memset(str, 'A', i));
    ck_assert_str_eq(str, "Hello");
    #pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_s21_memset_null) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_ptr_eq(s21_memset(NULL, 'A', 5), S21_NULL);
#pragma GCC diagnostic pop
}
END_TEST

Suite *s21_memset_suite(void) {
    Suite *s = suite_create("s21_memset");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memset_basic);
    tcase_add_test(tc_core, test_s21_memset_zero_n);
    tcase_add_test(tc_core, test_s21_memset_null);
    suite_add_tcase(s, tc_core);
    return s;
}
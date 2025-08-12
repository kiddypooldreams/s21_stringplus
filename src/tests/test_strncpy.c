#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strncpy_basic) {
    char dest[20] = {0};
    const char *src = "Hello";
    ck_assert_ptr_eq(s21_strncpy(dest, src, 5), strncpy(dest, src, 5));
    ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_s21_strncpy_zero_n) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-truncation"
    char dest[20] = "Test";
    const char *src = "Hello";
    ck_assert_ptr_eq(s21_strncpy(dest, src, 0), strncpy(dest, src, 0));
    ck_assert_str_eq(dest, "Test");
#pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_s21_strncpy_null_dest) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
#pragma GCC diagnostic ignored "-Wstringop-truncation"
    ck_assert_ptr_eq(s21_strncpy(NULL, "Hello", 5), NULL);
#pragma GCC diagnostic pop
}
END_TEST

Suite *s21_strncpy_suite(void) {
    Suite *s = suite_create("s21_strncpy");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strncpy_basic);
    tcase_add_test(tc_core, test_s21_strncpy_zero_n);
    tcase_add_test(tc_core, test_s21_strncpy_null_dest);
    suite_add_tcase(s, tc_core);
    return s;
}
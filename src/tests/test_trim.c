#include <check.h>
#include "../s21_string.h"

START_TEST(test_s21_trim_basic) {
    const char *src = "   Hello, world!   ";
    const char *trim_chars = " ";
    char *result = (char *)s21_trim(src, trim_chars);
    ck_assert_str_eq(result, "Hello, world!");
    if (result) free(result);
}
END_TEST

START_TEST(test_s21_trim_null) {
    ck_assert_ptr_eq(s21_trim(NULL, " "), NULL);
    ck_assert_ptr_eq(s21_trim("Hello", NULL), NULL);
}
END_TEST

START_TEST(test_s21_trim_empty) {
    const char *src = "";
    const char *trim_chars = " ";
    char *result = (char *)s21_trim(src, trim_chars);
    ck_assert_str_eq(result, "");
    if (result) free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
    Suite *s = suite_create("s21_trim");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_trim_basic);
    tcase_add_test(tc_core, test_s21_trim_null);
    tcase_add_test(tc_core, test_s21_trim_empty);
    suite_add_tcase(s, tc_core);
    return s;
}


#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strstr_basic) {
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
    const char *haystack = "Hello";
    const char *needle = "";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_null) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_ptr_eq(s21_strstr(NULL, "test"), NULL);
    #pragma GCC diagnostic pop
}
END_TEST

Suite *s21_strstr_suite(void) {
    Suite *s = suite_create("s21_strstr");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strstr_basic);
    tcase_add_test(tc_core, test_s21_strstr_empty_needle);
    tcase_add_test(tc_core, test_s21_strstr_null);
    suite_add_tcase(s, tc_core);
    return s;
}


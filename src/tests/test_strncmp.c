#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strncmp_equal) {
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_strncmp_different) {
    const char *str1 = "Hello";
    const char *str2 = "World";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_strncmp_zero_n) {
    const char *str1 = "Hello";
    const char *str2 = "World";
    ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

Suite *s21_strncmp_suite(void) {
    Suite *s = suite_create("s21_strncmp");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strncmp_equal);
    tcase_add_test(tc_core, test_s21_strncmp_different);
    tcase_add_test(tc_core, test_s21_strncmp_zero_n);
    suite_add_tcase(s, tc_core);
    return s;
}


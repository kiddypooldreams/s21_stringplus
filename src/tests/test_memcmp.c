#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_memcmp_equal) {
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_memcmp_different) {
    const char *str1 = "Hello";
    const char *str2 = "World";
    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_memcmp_zero_n) {
    const char *str1 = "Hello";
    const char *str2 = "World";
    ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

Suite *s21_memcmp_suite(void) {
    Suite *s = suite_create("s21_memcmp");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memcmp_equal);
    tcase_add_test(tc_core, test_s21_memcmp_different);
    tcase_add_test(tc_core, test_s21_memcmp_zero_n);
    suite_add_tcase(s, tc_core);
    return s;
}

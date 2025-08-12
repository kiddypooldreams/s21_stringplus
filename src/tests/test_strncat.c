#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strncat_basic) {
    char dest[20] = "Hello";
    char expected[20] = "Hello";
    const char *src = ", world!";
    //ck_assert_ptr_eq(s21_strncat(dest, src, 7), strncat(expected, src, 7));
    s21_strncat(dest, src, 7);
    strncat(expected, src, 7);
    ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncat_zero_n) {
    char dest[20] = "Hello";
    char expected[20] = "Hello";
    const char *src = ", world!";
    //ck_assert_ptr_eq(s21_strncat(dest, src, 0), strncat(expected, src, 0));
    s21_strncat(dest, src, 0);
    strncat(expected, src, 0);
    ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncat_null_dest) {
    ck_assert_ptr_eq(s21_strncat(NULL, "test", 5), S21_NULL);
}
END_TEST

Suite *s21_strncat_suite(void) {
    Suite *s = suite_create("s21_strncat");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strncat_basic);
    tcase_add_test(tc_core, test_s21_strncat_zero_n);
    tcase_add_test(tc_core, test_s21_strncat_null_dest);
    suite_add_tcase(s, tc_core);
    return s;
}


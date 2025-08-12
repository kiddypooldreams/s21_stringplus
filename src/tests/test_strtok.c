#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strtok_basic) {
    char str1[20] = "Hello,world!";
    char str2[20] = "Hello,world!";
    const char *delim = ",";
    char *token1 = s21_strtok(str1, delim);
    char *token2 = strtok(str2, delim);
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(NULL, delim);
    token2 = strtok(NULL, delim);
    ck_assert_str_eq(token1, token2);
}
END_TEST

START_TEST(test_s21_strtok_empty) {
    char str[20] = "";
    ck_assert_ptr_eq(s21_strtok(str, ","), strtok(str, ","));
}
END_TEST

START_TEST(test_s21_strtok_null) {
    ck_assert_ptr_eq(s21_strtok(NULL, ","), NULL);
}
END_TEST

Suite *s21_strtok_suite(void) {
    Suite *s = suite_create("s21_strtok");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strtok_basic);
    tcase_add_test(tc_core, test_s21_strtok_empty);
    tcase_add_test(tc_core, test_s21_strtok_null);
    suite_add_tcase(s, tc_core);
    return s;
}

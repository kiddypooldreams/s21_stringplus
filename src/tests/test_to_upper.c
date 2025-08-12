#include <check.h>
#include "../s21_string.h"

START_TEST(test_s21_to_upper_basic) {
    const char *str = "Hello, World!";
    char *result = (char *)s21_to_upper(str);
    ck_assert_str_eq(result, "HELLO, WORLD!");
    if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_null) {
    ck_assert_ptr_eq(s21_to_upper(NULL), NULL);
}
END_TEST

START_TEST(test_s21_to_upper_empty) {
    const char *str = "";
    char *result = (char *)s21_to_upper(str);
    ck_assert_str_eq(result, "");
    if (result) free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
    Suite *s = suite_create("s21_to_upper");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_to_upper_basic);
    tcase_add_test(tc_core, test_s21_to_upper_null);
    tcase_add_test(tc_core, test_s21_to_upper_empty);
    suite_add_tcase(s, tc_core);
    return s;
}


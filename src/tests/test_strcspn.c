#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strcspn_basic) {
    const char *str1 = "Hello, world!";
    const char *str2 = ",!";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_empty) {
    const char *str1 = "";
    const char *str2 = "abc";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_null) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_int_eq(s21_strcspn(NULL, "abc"), 0);
    #pragma GCC diagnostic pop
}
END_TEST

Suite *s21_strcspn_suite(void) {
    Suite *s = suite_create("s21_strcspn");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strcspn_basic);
    tcase_add_test(tc_core, test_s21_strcspn_empty);
    tcase_add_test(tc_core, test_s21_strcspn_null);
    suite_add_tcase(s, tc_core);
    return s;
}

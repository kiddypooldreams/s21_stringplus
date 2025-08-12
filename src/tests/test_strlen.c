#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strlen_basic) {
    const char *str = "Hello, world!";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_empty) {
    const char *str = "";
    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_null) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_int_eq(s21_strlen(NULL), 0);
    #pragma GCC diagnostic pop
}
END_TEST

Suite *s21_strlen_suite(void) {
    Suite *s = suite_create("s21_strlen");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strlen_basic);
    tcase_add_test(tc_core, test_s21_strlen_empty);
    tcase_add_test(tc_core, test_s21_strlen_null);
    suite_add_tcase(s, tc_core);
    return s;
}

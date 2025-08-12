#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strerror_valid) {
    ck_assert_str_eq(s21_strerror(0), strerror(0));
    ck_assert_str_eq(s21_strerror(1), strerror(1));
}
END_TEST

// START_TEST(test_s21_strerror_invalid) {
//     ck_assert_str_eq(s21_strerror(-1), strerror(-1));
//     ck_assert_str_eq(s21_strerror(1000), strerror(1000));
// }
// END_TEST

Suite *s21_strerror_suite(void) {
    Suite *s = suite_create("s21_strerror");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strerror_valid);
    //tcase_add_test(tc_core, test_s21_strerror_invalid);
    suite_add_tcase(s, tc_core);
    return s;
}


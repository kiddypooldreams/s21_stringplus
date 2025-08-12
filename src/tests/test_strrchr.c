#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strrchr_basic) {
    const char *str = "Hello, world!";
    int c = 'o';
    ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_null) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_ptr_eq(s21_strchr(NULL, 'a'), S21_NULL);
    #pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
    const char *str = "Hello, world!";
    ck_assert_ptr_eq(s21_strchr(str, 'z'), strchr(str, 'z'));
}
END_TEST

Suite *s21_strrchr_suite(void) {
    Suite *s = suite_create("s21_strrchr");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strrchr_basic);
    tcase_add_test(tc_core, test_s21_strrchr_null);
    tcase_add_test(tc_core, test_s21_strrchr_not_found);
    suite_add_tcase(s, tc_core);
    return s;
}


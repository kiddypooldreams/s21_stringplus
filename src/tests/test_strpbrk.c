#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_strpbrk_basic) {
    const char *str1 = "Hello, world!";
    const char *str2 = ",!";
    ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
    const char *str1 = "Hello";
    const char *str2 = "xyz";
    ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_null) {
    #pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnonnull"
    ck_assert_ptr_eq(s21_strpbrk(NULL, "abc"), NULL);
    #pragma GCC diagnostic pop
}
END_TEST

Suite *s21_strpbrk_suite(void) {
    Suite *s = suite_create("s21_strpbrk");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_strpbrk_basic);
    tcase_add_test(tc_core, test_s21_strpbrk_no_match);
    tcase_add_test(tc_core, test_s21_strpbrk_null);
    suite_add_tcase(s, tc_core);
    return s;
}

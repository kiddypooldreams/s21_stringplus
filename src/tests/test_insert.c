#include <check.h>
#include "../s21_string.h"

START_TEST(test_s21_insert_basic) {
    const char *src = "Hello, world!";
    const char *str = "beautiful ";
    char *result = (char *)s21_insert(src, str, 7);
    ck_assert_str_eq(result, "Hello, beautiful world!");
    if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_null) {
    ck_assert_ptr_eq(s21_insert(NULL, "test", 0), NULL);
    ck_assert_ptr_eq(s21_insert("Hello", NULL, 0), NULL);
}
END_TEST

START_TEST(test_s21_insert_invalid_index) {
    const char *src = "Hello";
    const char *str = "test";
    ck_assert_ptr_eq(s21_insert(src, str, 10), NULL);
}
END_TEST

Suite *s21_insert_suite(void) {
    Suite *s = suite_create("s21_insert");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_insert_basic);
    tcase_add_test(tc_core, test_s21_insert_null);
    tcase_add_test(tc_core, test_s21_insert_invalid_index);
    suite_add_tcase(s, tc_core);
    return s;
}

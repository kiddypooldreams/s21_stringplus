#include <check.h>
#include <string.h>
#include "../s21_string.h"

START_TEST(test_s21_memcpy_basic) {
    char dest[20] = {0};
    const char *src = "Hello";
    ck_assert_ptr_eq(s21_memcpy(dest, src, 5), memcpy(dest, src, 5));
    ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_s21_memcpy_zero_n) {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wnonnull"
    char dest[20] = "Test";
    const char *src = "Hello";
    ck_assert_ptr_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));
    ck_assert_str_eq(dest, "Test");
    #pragma GCC diagnostic pop
}
END_TEST

START_TEST(test_s21_memcpy_null_dest) {
    ck_assert_ptr_eq(s21_memcpy(NULL, "Hello", 5), S21_NULL);
}
END_TEST

Suite *s21_memcpy_suite(void) {
    Suite *s = suite_create("s21_memcpy");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_s21_memcpy_basic);
    tcase_add_test(tc_core, test_s21_memcpy_zero_n);
    tcase_add_test(tc_core, test_s21_memcpy_null_dest);
    suite_add_tcase(s, tc_core);
    return s;
}

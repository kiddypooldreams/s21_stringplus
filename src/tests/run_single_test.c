#include <check.h>
#include "../s21_string.h"

Suite *s21_memchr_suite(void); // Объявление Suite из test_memchr.c

int main(void) {
    int number_failed = 0;
    SRunner *sr = srunner_create(s21_memchr_suite());
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
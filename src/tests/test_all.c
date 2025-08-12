#include <check.h>
#include "../s21_string.h"

// Объявления функций создания Suite из каждого тестового файла
Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);
Suite *s21_to_upper_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

int main(void) {
    int number_failed = 0;
    SRunner *sr = srunner_create(NULL);
    
    // Добавляем все Suite
    srunner_add_suite(sr, s21_memcmp_suite());

    // Запускаем все тесты
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? 0 : 1;
}
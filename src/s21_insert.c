#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  int error = 0;
  s21_size_t source_length = 0, insert_length = 0, result_lenght = 0;
  if (src != S21_NULL || str != S21_NULL) {
    source_length = s21_strlen(src);
    insert_length = s21_strlen(str);
    result_lenght = insert_length + source_length;
  } else
    error = 1;
  if (start_index >= source_length) {
    error = 1;
  }
  if (!error && src && str)
    result = (char *)malloc((result_lenght + 1) * sizeof(char));
  if (result != S21_NULL && !error) {
    s21_strncpy(result, src, start_index);
    s21_strncpy(result + start_index, str, insert_length);
    s21_strncpy(result + start_index + insert_length, src + start_index,
                source_length - start_index);
  }
  return result;
}

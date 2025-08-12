#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  s21_size_t length = s21_strlen(str);
  if (str) {
    result = (char *)malloc((length + 1) * sizeof(char));
  }
  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] >= 97 && str[i] <= 122)
        result[i] = str[i] - 32;
      else
        result[i] = str[i];
    }
    result[length] = '\0';
  }
  return result;
}
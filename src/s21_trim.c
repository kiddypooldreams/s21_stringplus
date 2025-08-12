#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  s21_size_t i = 0;
  if (src && trim_chars) {
    for (; src[i] && s21_strchr(trim_chars, src[i]); i++);
    src += i;
    for (i = s21_strlen(src) - 1; src[i] && s21_strrchr(trim_chars, src[i]);
         i--);
  }
  if (src && trim_chars) result = malloc((i + 1) * sizeof(char));
  if (result) s21_strncpy(result, src, i + 1);
  return (void *)result;
}

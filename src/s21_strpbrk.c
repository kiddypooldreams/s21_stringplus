#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;

  if (str1 && str2) {
    for (; *str1 && res == S21_NULL; str1++)
      for (const char *p2 = str2; *p2 && res == S21_NULL; p2++)
        if (*str1 == *p2) res = (char *)str1;
  }
  return res;
}
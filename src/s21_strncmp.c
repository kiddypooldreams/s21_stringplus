#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (n == 0) return 0;

  const char *p1 = str1, *p2 = str2;
  int res;

  do {
    res = *p1 - *p2++;
  } while (--n && res == 0 && *p1++);
  return res;
}
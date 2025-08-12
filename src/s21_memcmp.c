#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = str1, *p2 = str2;
  int res = 0;

  while (n-- && res == 0) res = *p1++ - *p2++;
  return res;
}
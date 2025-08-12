#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;

  if (str != S21_NULL) {
    const unsigned char *p = str;
    while (n-- && res == S21_NULL)
      if (*p++ == (unsigned char)c) res = ((void *)--p);
  }
  return res;
}
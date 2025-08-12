#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    const char *f = src;
    char *t = dest;
    while (*t) t++;

    while (n-- && *f) *t++ = *f++;
    *t = 0;
  }
  return dest;
}
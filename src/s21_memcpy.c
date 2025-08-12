#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    const char *f = src;
    char *t = dest;

    while (n--) *t++ = *f++;
  }
  return dest;
}
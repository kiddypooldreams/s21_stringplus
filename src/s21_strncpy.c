#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *t = dest;
  if (dest != S21_NULL && src != S21_NULL) {
    while (n && (*t++ = *src++)) n--;
    while (n-- && *t++) *t = '\0';
  }
  return dest;
}
#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;

  if (str) {
    do {
      if (*str == c) res = (char *)str;
    } while (*str++);
  }
  return res;
}
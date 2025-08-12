#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;

  if (str != S21_NULL) {
    do {
      if (*str == c) res = (char *)str;
    } while (*str++ && res == S21_NULL);
  }
  return res;
}
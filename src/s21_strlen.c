#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *p = str;
  if (str != NULL) {
    for (p = str; *p; ++p);
  }
  return p - str;
}
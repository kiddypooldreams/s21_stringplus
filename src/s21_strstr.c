#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *result = S21_NULL;
  if (needle[0] == '\0' && haystack && needle) {
    result = haystack;
  } else if (haystack && needle) {
    s21_size_t needle_length = s21_strlen(needle);
    for (int i = 0; haystack[i] != '\0'; i++) {
      if (haystack[i] == needle[0]) {
        if (s21_strncmp(&haystack[i], needle, needle_length) == 0) {
          result = &haystack[i];
        }
      }
    }
  }
  return (char *)result;
}

#include <errno.h>

#include "s21_string.h"

char *s21_strerror(int errnum) {
  const char *const errlist[] = {
#define S21_S(n, str) [n] = str,
#if defined(__APPLE__)
#include "s21_errlist/s21_apple_errlists.h"
#elif defined(__linux__)
#include "s21_errlist/s21_linux_errlists.h"
#endif
#undef S21_S
  };

  int errlist_size = (sizeof(errlist) / sizeof(errlist[0]));

  return (errnum >= 0 && errnum <= errlist_size) ? (char *)errlist[errnum]
                                                 : "Unknown error";
}
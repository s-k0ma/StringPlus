#include "s21_errno.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *out = S21_NULL;
  static char error[256];
  if (errnum >= 0 && errnum <= MAX_ERR) {
    out = (char *)errors[errnum];
  } else {
    s21_sprintf(error, "%s%d", ERR, errnum);
    out = error;
  }
  return (char *)out;
}
#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  if (str != S21_NULL) {
    ptr = str;
    while (*ptr && s21_strchr(delim, *ptr)) {
      *ptr++ = '\0';
    }
  }
  if (ptr != S21_NULL) {
    if (*ptr != '\0') {
      str = ptr;
      while (*ptr && !s21_strchr(delim, *ptr)) {
        ptr++;
      }
      while (*ptr && s21_strchr(delim, *ptr)) {
        *ptr++ = '\0';
      }
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }

  return str;
}
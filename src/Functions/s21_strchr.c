#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *ptr = (char *)str;
  char sym = (char)c;
  char *res = S21_NULL;

  while (*ptr != '\0') {
    if (*ptr == sym) {
      break;
    }
    ptr++;
  }
  if (*ptr != '\0' && sym != '\0') {
    res = ptr;
  }
  if (sym == '\0') res = ptr;

  return res;
}
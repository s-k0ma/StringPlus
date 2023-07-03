#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *ptr = (char *)str;
  char *res = S21_NULL;
  s21_size_t length = s21_strlen(str);

  for (int i = length; i >= 0; i--) {
    if (ptr[i] == c) {
      res = ((char *)ptr) + i;
      break;
    }
  }
  return res;
}
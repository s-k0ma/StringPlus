#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *first_str = (unsigned char *)str1;
  unsigned char *second_str = (unsigned char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*first_str != *second_str) {
      res = *first_str - *second_str;
      break;
    }
    ++first_str;
    ++second_str;
  }

  return res;
}
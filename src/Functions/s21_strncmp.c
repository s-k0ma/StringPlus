#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (int i = 0; i < (int)n; i++) {
    result = result == 0 ? str1[i] - str2[i] : result;
    if (str1[i] == '\0' || str2[i] == '\0') break;
  }
  return result;
}
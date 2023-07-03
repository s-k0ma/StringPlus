#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  int matched = 0;
  for (int i = 0; i <= (int)s21_strlen(str1); i++) {
    for (int j = 0; j <= (int)s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        if (matched == 0) {
          res = i;
          matched++;
        } else {
          res = (int)res < i ? res : (s21_size_t)i;
        }
      }
    }
  }
  return res;
}
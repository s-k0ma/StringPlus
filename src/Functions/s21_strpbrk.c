#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *str = (char *)str1;
  char *sym = (char *)str2;
  char *result = S21_NULL;
  int flag = 0;
  for (int i = 0; i < (int)s21_strlen(str) && flag == 0; i++) {
    for (int j = 0; j < (int)s21_strlen(sym) && flag == 0; j++) {
      if (str[i] == sym[j]) {
        flag = 1;
        result = str + i;
      }
    }
  }
  return result;
}
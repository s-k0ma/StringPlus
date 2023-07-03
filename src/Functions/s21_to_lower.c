#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *low_str = S21_NULL;
  if (str != S21_NULL) {
    low_str = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
    for (int i = 0; i <= (int)s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        low_str[i] = (str[i] - 'A') + 'a';
      } else
        low_str[i] = str[i];
    }
  }
  return (void *)low_str;
}
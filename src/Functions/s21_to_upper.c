#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *up_str = S21_NULL;
  if (str != S21_NULL) {
    up_str = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
    for (int i = 0; i <= (int)s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        up_str[i] = (str[i] - 'a') + 'A';
      } else
        up_str[i] = str[i];
    }
  }
  return (void *)up_str;
}
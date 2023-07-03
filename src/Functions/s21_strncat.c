#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i, j;
  s21_size_t length = s21_strlen(dest);

  for (i = length, j = 0; i < (length + n) && src[j] != '\0'; i++, j++) {
    dest[i] = src[j];
  }
  return dest;
}

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_str = (char *)dest;
  char *src_str = (char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    dest_str[i] = src_str[i];
  }
  return dest;
}

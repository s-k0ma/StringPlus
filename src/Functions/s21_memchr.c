#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int match_found_flag = 0;
  char *string_to_iterate = (char *)str;
  char *result_ptr = (char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    if (string_to_iterate[i] == c) {
      result_ptr = &string_to_iterate[i];
      match_found_flag = 1;
    }
  }
  if (match_found_flag) {
    return result_ptr;
  } else {
    return S21_NULL;
  }
}
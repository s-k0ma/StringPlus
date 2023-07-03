#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *str = (char *)haystack;
  char *result = S21_NULL;
  if (s21_strlen(haystack) == 0 && s21_strlen(needle) == 0) {
    result = "";
  } else {
    while (*str != '\0') {
      if (s21_strncmp(str, needle, s21_strlen(needle)) == 0) {
        result = str;
        break;
      }
      str++;
    }
  }
  return result;
}
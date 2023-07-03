#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_str = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    char *begin_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*begin_str && s21_strchr(trim_chars, *begin_str)) {
      begin_str++;
    }
    while (end_str != begin_str && s21_strchr(trim_chars, *(end_str - 1))) {
      end_str--;
    }
    trim_str = (char *)calloc((end_str - begin_str + 1), sizeof(char));
    s21_strncpy(trim_str, begin_str, end_str - begin_str);
    *(trim_str + (end_str - begin_str)) = '\0';
  } else if (src != S21_NULL && trim_chars == S21_NULL) {
    char *begin_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*begin_str && s21_isspace(*begin_str)) {
      begin_str++;
    }
    while (end_str != begin_str && s21_isspace(*(end_str - 1))) {
      end_str--;
    }
    trim_str = (char *)calloc((end_str - begin_str + 1), sizeof(char));
    s21_strncpy(trim_str, begin_str, end_str - begin_str);
    *(trim_str + (end_str - begin_str)) = '\0';
  }
  return (void *)trim_str;
}

// #include "s21_string.h"

// void *s21_trim(const char *src, const char *trim_chars) {
//   char *trim_str = S21_NULL;
//   if (src != S21_NULL && trim_chars != S21_NULL) {
//     char *begin_str = (char *)src;
//     char *end_str = (char *)src + s21_strlen(src);
//     while (*begin_str && s21_strchr(trim_chars, *begin_str)) {
//       begin_str++;
//     }
//     while (end_str != begin_str && s21_strchr(trim_chars, *(end_str - 1))) {
//       end_str--;
//     }
//     trim_str = (char *)calloc((end_str - begin_str + 1), sizeof(char));
//     s21_strncpy(trim_str, begin_str, end_str - begin_str);
//     *(trim_str + (end_str - begin_str)) = '\0';
//   } else if (src != S21_NULL && trim_chars == S21_NULL) {
//     char *begin_str = (char *)src;
//     char *end_str = (char *)src + s21_strlen(src);
//     trim_str = (char *)calloc((s21_strlen(src) + 1), sizeof(char));
//     s21_strncpy(trim_str, begin_str, end_str - begin_str);
//     *(trim_str + s21_strlen(src)) = '\0';
//   }
//   return (void *)trim_str;
// }
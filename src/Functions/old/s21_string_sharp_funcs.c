#include "../s21_string.h"

char *s21_to_upper(const char *str) {
  static char res[S21_BUFF_SIZE];
  int len = s21_strlen(str);
  int i = 0;
  for (; i < len; i++) {
    if ((str[i] > 96) && (str[i] < 123)) {
      res[i] = str[i] + 'A' - 'a';
    } else {
      res[i] = str[i];
    }
  }
  res[i] = '\0';
  return res;
}
char *s21_to_lower(const char *str) {
  int len = s21_strlen(str);
  static char res[S21_BUFF_SIZE];
  int i = 0;
  for (; i < len; i++) {
    if ((str[i] > 64) && (str[i] < 91)) {
      res[i] = str[i] + 'a' - 'A';
    } else {
      res[i] = str[i];
    }
  }
  res[i] = '\0';
  return res;
}

char *s21_insert(const char *src, const char *str, size_t start_index) {
  size_t len_src = s21_strlen(src);
  size_t len = s21_strlen(str);

  if (start_index > len_src) return NULL;

  static char res[S21_BUFF_SIZE];
  size_t src_i = 0, i = 0;
  while (src_i < start_index) {
    res[src_i] = src[src_i];
    src_i++;
  }
  for (; i < len; i++) res[src_i + i] = str[i];
  while (src_i + i < len_src + len) {
    res[src_i + i] = src[src_i];
    src_i++;
  }
  res[i + src_i] = '\0';
  return res;
}

char *s21_trim(const char *src, const char *trim_chars) {
  static char res_static[S21_BUFF_SIZE];
  char *res = NULL;  // to be able to return same string
  int len = s21_strlen(src);
  int new_start = 0;
  int new_end = len - 1;

  int src_i = 0;
  while (src_i < len && s21_strchr(trim_chars, src[src_i])) new_start = ++src_i;

  src_i = len - 1;
  while (src_i >= 0 && s21_strchr(trim_chars, src[src_i])) new_end = --src_i;

  if ((new_start == 0) && (new_end == len - 1))  //!! return same string
    res = (char *)src;
  else {
    res = res_static;
    int res_i = 0;
    if (new_start < len)
      for (; new_start <= new_end; res_i++, new_start++)  // looks like shit
        res[res_i] = src[new_start];
    res[res_i] = '\0';
  }
  return res;
}

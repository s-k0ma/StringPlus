#include "../s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  void *res = NULL;
  unsigned char *ptr = (unsigned char *)arr;
  for (; ptr - (unsigned char *)arr < (int)n && *ptr; ptr++) {
    if ((int)(*ptr) == c) {
      res = ptr;
      break;
    }
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int res = 0;
  while (res == 0 && ptr1 - (unsigned char *)str1 < (int)n) {
    res = *ptr1 - *ptr2;
    ptr1++;
    ptr2++;
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ptr_dest = (unsigned char *)dest;
  unsigned char *ptr_src = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    *ptr_dest = *ptr_src;
    ptr_dest++;
    ptr_src++;
  }
  return dest;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *ptr = (char)c;
    ptr++;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr_dest = dest;
  char *ptr_src = (char *)src;
  while (*ptr_dest) {
    ptr_dest++;
  }
  for (s21_size_t i = 0; i < n && *src; i++) {
    *ptr_dest = *ptr_src;
    ptr_dest++;
    ptr_src++;
  }
  *ptr_dest = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *ptr = (char *)str;
  while (*ptr != c && *ptr) {
    ptr++;
  }
  if (*ptr != c) ptr = NULL;
  return ptr;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *ptr1 = str1;
  const char *ptr2 = str2;
  int res = 0;
  while (res == 0 && ptr1 - str1 < (int)n) {
    res = *ptr1 - *ptr2;
    ptr1++;
    ptr2++;
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr_dest = dest;
  char *ptr_src = (char *)src;
  while (*src && ptr_src - src < (int)n) {
    *ptr_dest = *ptr_src;
    ptr_dest++;
    ptr_src++;
  }

  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int not_in_str2 = 1;
  while (str1[len] && not_in_str2) {
    for (int i = 0; str2[i]; i++) {
      if (str1[len] == str2[i]) not_in_str2 = 0;
    }
    if (not_in_str2) len++;
  }
  return len;
}

char *s21_strerror(int errnum) {
  static char err_list[ERR_MAX][100] = ERR_LIST;
  static char err_buf[100];
  char *err;
  if (errnum >= 0 && errnum < ERR_MAX) {
    err = err_list[errnum];
  } else {
    sprintf(err_buf, "%s%d", UNKNOWN_ERR, errnum);
    err = err_buf;
  }
  return err;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = NULL;
  char *ptr1 = (char *)str1;
  char *ptr2;
  while (*ptr1) {
    ptr2 = (char *)str2;
    while (*ptr2) {
      if (*ptr1 == *ptr2) {
        res = ptr1;
        break;
      }
      ptr2++;
    }
    if (res == NULL)
      ptr1++;
    else
      break;
  }
  return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = NULL;
  if (!*needle) {
    res = (char *)haystack;
  }
  char *ptr_hay = s21_strchr(haystack, needle[0]);
  s21_size_t len_needle = s21_strlen(needle);
  while (ptr_hay && !res) {
    if (!s21_strncmp(ptr_hay, needle, len_needle)) {
      res = ptr_hay;
    }
    ptr_hay++;
    ptr_hay = s21_strchr(ptr_hay, needle[0]);
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = NULL;
  int str_len = s21_strlen(str);
  char *ptr = (char *)str + str_len;
  for (; ptr - str >= 0; ptr--) {
    if ((int)(*ptr) == c) {
      res = ptr;
      break;
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *remember_pos = NULL;
  char *p = NULL;
  if (str == NULL) str = remember_pos;
  if (str) p = s21_strpbrk(str, delim);
  if (p) {
    *p++ = '\0';
    remember_pos = p;
    p = str;
  } else if (remember_pos) {
    p = remember_pos;
    remember_pos = NULL;
  } else if (str && *str) {
    p = str;
  }
  return p;
}

long long int s21_atoi(const char *str, int radix) {
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+')
    str++;
  if (radix == 16 && *str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
    str += 2;
  } else if (radix == 8 && *str == '0') {
    str++;
  }
  long long int value = 0;
  char *hash = "0123456789abcdefghijklmnopqrstuvwxyz";
  char cur_hash[32] = {'\0'};
  for (int j = 0; j < radix; j++) cur_hash[j] = hash[j];
  int i = 0;
  char *chr_pos;
  while (str[i] && (chr_pos = s21_strchr(cur_hash, str[i]))) {
    int tmp = chr_pos - cur_hash;
    value = value * radix + tmp;
    i++;
  }
  return (value * sign);
}

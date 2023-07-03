#include "../s21_string.h"

s21_specifiers init_spec() {
  s21_specifiers s;
  s.lengths = s.types = 0;
  s.precisions = -1;
  s.widths = s.flags.minus = s.flags.plus = s.flags.sharp = s.flags.space =
      s.flags.zero = 0;
  s.assignment_suppress = false;
  return s;
}

char *s21_itoa(unsigned long value, char *buf, int radix) {
  if (radix < 2 || radix > 36) radix = 10;  //!!// return buf;
  char tmp[S21_BUFF_SIZE];
  char *ret = buf;
  char *hash_ = "0123456789abcdefghijklmnopqrstuvwxyz";
  int i = 0;

  do {
    tmp[i] = hash_[value % radix];
    value /= radix;
    i++;
  } while (i < S21_BUFF_SIZE - 2 && value);
  i--;
  while (i > -1) {
    *buf = tmp[i];
    buf++;
    i--;
  }
  *buf = '\0';
  return ret;
}

char *s21_strcpy(char *dest, char *src) {  // cpy from src to dest
  char *dest_back = dest;
  for (; *src; src++, dest++) {
    *dest = *src;
  }
  *(dest) = '\0';
  return dest_back;
}

bool valid_specifier_finder(const char **format, va_list *vaList,
                            s21_specifiers *s, char mode) {
  bool isValidSpec = true;
  const char *backup = *format;
  (*format)++;
  if (mode == 'p') parseFlags(format, s);
  if (**format == '*') {
    if (mode == 'p')
      s->widths = va_arg(*vaList, int);
    else if (mode == 's')
      s->assignment_suppress = true;
    (*format)++;
  } else if ((**format >= '1' && **format <= '9')) {
    s->widths = s21_atoi(*format, 10);
    while (**format >= '0' && **format <= '9') ((*format)++);
  }
  if (**format == '.' && mode == 'p') {
    (*format)++;
    if (**format == '*') {
      s->flags.zero = 0;
      (*format)++;
      s->precisions = va_arg(*vaList, int);
    } else if ((**format >= '0' && **format <= '9')) {
      s->precisions = s21_atoi(*format, 10);
      while (**format >= '0' && **format <= '9') ((*format)++);
    } else {
      s->precisions = 0;
    }
  }
  char *len_ptr = s21_strchr(S21_LENGH_STR, **format);
  if (len_ptr) {
    s->lengths = *len_ptr;
    (*format)++;
  }
  char *type_ptr = s21_strchr(S21_TYPES_STR, **format);
  if (type_ptr) {
    s->types = *type_ptr;
    (*format)++;
  } else {
    isValidSpec = false;
    if (mode == 's') format++;
  }
  if (!isValidSpec && mode == 'p') *format = backup;
  return isValidSpec;
}

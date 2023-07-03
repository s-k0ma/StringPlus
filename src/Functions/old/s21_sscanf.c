#include <locale.h>

#include "../../s21_string.h"
// #include "s21_string.c"

int s21_sscanf(const char *buffer, char *format, ...) {
  int var_written = 0;
  va_list vaList;
  va_start(vaList, format);
  var_written = read_format_str(buffer, format, &vaList);
  va_end(vaList);
  return var_written;
}

int read_format_str(const char *buffer, const char *format, va_list *vaList) {
  bool error = false;
  int var_written = 0;
  while (*format && !error) {
    if (*format == *buffer) {
      format++;
      buffer++;
    } else if (*format == '%' && *buffer) {
      if (*(1 + format) != '%') {
        s21_specifiers s = init_spec();
        if (valid_specifier_finder(&format, vaList, &s, 's')) {
          buffer = read_buffer(buffer, &s, vaList, &error);
          if (!error) var_written++;
        }
      } else
        format++;
    } else
      format++;
  }
  return var_written;
}

const char *read_buffer(const char *buffer, s21_specifiers *s, va_list *vaList,
                        bool *error) {
  const char *new_buffer;
  bool is_signed = false;
  switch (s->types) {
    case 'p':
    case 'i':
      if (*buffer == '+' || *buffer == '-') {
        is_signed = true;
        buffer++;
      }
      if (*buffer == '0' && (*(buffer + 1) == 'x' || *(buffer + 1) == 'X')) {
        if (is_signed) buffer--;
        new_buffer = write_integer(buffer, s, vaList, 16, HEX_SYM, error);
      } else if (*buffer == '0') {
        if (is_signed) buffer--;
        new_buffer = write_integer(buffer, s, vaList, 8, OCT_SYM, error);
      } else {
        if (is_signed) buffer--;
        new_buffer = write_integer(buffer, s, vaList, 10, DEC_SYM, error);
      }
      break;
    case 'd':
      new_buffer = write_integer(buffer, s, vaList, 10, DEC_SYM, error);
      break;
    case 's':
      new_buffer = write_str(buffer, s, vaList);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      new_buffer = write_float(buffer, s, vaList, error);
      break;
    case 'c':
      s->widths = 1;
      new_buffer = write_str(buffer, s, vaList);
      break;
    case 'o':
      new_buffer = write_integer(buffer, s, vaList, 8, OCT_SYM, error);
      break;
    case 'u':
      new_buffer = write_integer(buffer, s, vaList, 10, DEC_SYM, error);
      break;
    case 'x':
    case 'X':
      new_buffer = write_integer(buffer, s, vaList, 16, HEX_SYM, error);
      break;
  }
  return new_buffer;
}

const char *write_integer(const char *buffer, s21_specifiers *s,
                          va_list *vaList, int radix, const char *available_sym,
                          bool *error) {
  char num_str[MAX_BUFFER_SIZE] = {'\0'};
  int counter = MAX_BUFFER_SIZE;
  long long int num = 0;
  long long unsigned int unsigned_num = 0;
  if (s->widths > 0) counter = s->widths;
  int i = 0;
  while (*buffer && s21_strchr(available_sym, (int)*buffer) && i < counter) {
    num_str[i++] = *buffer++;
  }
  if (*num_str) {
    if (!(s->assignment_suppress)) {
      if (((s->types) == 'i') || ((s->types) == 'd')) {
        num = s21_atoi(num_str, radix);
        if ((s->lengths) == 'h') {
          *(va_arg(*vaList, short int *)) = (short int)num;
        } else if ((s->lengths) == 'l') {
          *(va_arg(*vaList, long int *)) = (long int)num;
        } else if ((s->lengths) == 'L') {
          *(va_arg(*vaList, long long int *)) = num;
        } else {
          *(va_arg(*vaList, int *)) = (int)num;
        }
      } else if (((s->types) == 'u') || ((s->types) == 'o') ||
                 ((s->types) == 'x') || ((s->types) == 'X')) {
        unsigned_num = s21_atoi(num_str, radix);
        if ((s->lengths) == 'h') {
          *(va_arg(*vaList, short unsigned int *)) =
              (short unsigned int)unsigned_num;
        } else if ((s->lengths) == 'l') {
          *(va_arg(*vaList, long unsigned int *)) =
              (long unsigned int)unsigned_num;
        } else if ((s->lengths) == 'L') {
          *(va_arg(*vaList, long long unsigned int *)) = unsigned_num;
        } else {
          *(va_arg(*vaList, unsigned int *)) = (unsigned int)unsigned_num;
        }
      } else if ((s->types) == 'p') {
        unsigned_num = s21_atoi(num_str, radix);
        *(va_arg(*vaList, void **)) = (void *)unsigned_num;
      }
    }
    while (*buffer && *buffer == ' ') buffer++;
  } else {
    *error = true;
  }
  return buffer;
}

const char *write_str(const char *buffer, s21_specifiers *s, va_list *vaList) {
  char str_buf[MAX_BUFFER_SIZE] = {'\0'};
  wchar_t wstr_buf[MAX_BUFFER_SIZE];
  int counter = MAX_BUFFER_SIZE;
  if ((s->widths) > 0) counter = (s->widths);
  int i = 0;
  if ((s->lengths) == 'l') {
    while (*buffer != ' ' && i < counter) {
      mbtowc((wstr_buf + i), buffer, sizeof(wchar_t));
      buffer += sizeof(wchar_t);
      i++;
    }
  } else {
    while (*buffer && *buffer != ' ' && i < counter) str_buf[i++] = *(buffer++);
  }
  if (!(s->assignment_suppress)) {
    if ((s->lengths) == 'l') {
      if ((s->types) == 'c') {
        *(va_arg(*vaList, wchar_t *)) = wstr_buf[0];
      } else {
        wcsncpy((va_arg(*vaList, wchar_t *)), wstr_buf, i);
      }
    } else {
      if ((s->types) == 'c') {
        ;
        *(va_arg(*vaList, char *)) = str_buf[0];
      } else {
        s21_strncpy((va_arg(*vaList, char *)), str_buf, i + 1);
      }
    }
  }
  while (*buffer && *(buffer) == ' ') {
    buffer++;
  }
  return buffer;
}

const char *write_float(const char *buffer, s21_specifiers *s, va_list *vaList,
                        bool *error) {
  int counter = MAX_BUFFER_SIZE;
  if (s->widths > 0) counter = s->widths;
  int sign = 1;
  if (*buffer == '-') {
    sign = -1;
    buffer++;
    counter--;
  } else if (*buffer == '+') {
    buffer++;
    counter--;
  }
  if (*buffer && (isdigit(*buffer) || *buffer == '.') && counter > 0) {
    long double num = 0;
    while (*buffer && isdigit(*buffer) && counter-- > 0)
      num = num * 10 + (*buffer++ - '0');
    if (*buffer == '.' && counter-- > 0) {
      int i = 0;
      buffer++;
      while (*(buffer) && isdigit(*buffer) && counter-- > 0)
        num = num + (*buffer++ - '0') / pow(10, ++i);
    }
    int e_num = 0;
    if (*buffer == 'e' && counter-- > 0) {
      int e_sign = 1;
      buffer++;
      if (*buffer == '-' && counter-- > 0) {
        buffer++;
        e_sign = -1;
      } else if (*buffer == '+' && counter-- > 0) {
        buffer++;
      }
      if (isdigit(*buffer) && counter > 0) {
        while (*buffer && isdigit(*buffer) && counter-- > 0) {
          e_num = e_num * 10 + (*buffer++ - '0');
        }
        e_num *= e_sign;
      } else {
        if (*buffer == '-' || *buffer == '+')
          buffer -= 1;
        else
          buffer -= 2;
      }
    }
    num *= sign;
    num *= pow(10, e_num);
    if (!s->assignment_suppress) {
      if (s->lengths == 'l')
        *(va_arg(*vaList, double *)) = (double)num;
      else if (s->lengths == 'L')
        *(va_arg(*vaList, long double *)) = num;
      else
        *(va_arg(*vaList, float *)) = (float)num;
    }
    while (*buffer && *(buffer) == ' ') buffer++;
  } else
    *error = true;
  return buffer;
}

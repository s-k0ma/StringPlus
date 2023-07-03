// #include <locale.h>
// #include <wchar.h>

#include "../s21_string.h"
// #include "s21_string_sharp_funcs.c"

/**
 * @brief sends formatted output to a string pointed to, by buffer
 * @param bufer Storage location for output
 * @param format Format-control string
 * @param ... Optional arguments
 * @return The number of characters written, or -1 if an error occurred. If
 * buffer or format is a null pointer, the invalid parameter handler is invoked,
 * as described in Parameter validation. If execution is allowed to continue,
 * these functions return -1 and set errno to EINVAL. s21_sprintf returns the
 * number of bytes stored in buffer, not counting the terminating null
 * character.
 * @retval int
 *
 * @todo remove #include <string.h>
 *  * */
int s21_sprintf(char *buffer, const char *format, ...) {
  bool something_goes_wrong = false;
  char *buffer_start = buffer;
  va_list vaList;

  va_start(vaList, format);

  char *format_ = (char *)format;
  s21_dump_to_buf(buffer, format_, &vaList);

  va_end(vaList);
  return (something_goes_wrong) ? -1 : buffer_start - buffer;
}
int s21_dump_to_buf(char *buffer, const char *format, va_list *vaList) {
  while (*format) {
    bool is_valid = false;
    if (*format == '%') {
      if (*(1 + format) != '%') {
        s21_specifiers s = init_spec();

        if ((is_valid = valid_specifier_finder(&format, vaList, &s, 'p'))) {
          spec_reproc(&s);
          insertFormatedData(&buffer, &s, vaList);
        }
      } else
        format++;
    }
    if (!is_valid) {
      *buffer = *format;

      if (*format != 0) {
        format++;
        buffer++;
      }
    }
  }
  *buffer = '\0';
  return 0;
}

int parseFlags(const char **format, s21_specifiers *s) {
  bool exit = false;
  while (**format && !exit) {
    switch (**format) {
      case '-':
        s->flags.minus = 1;
        break;
      case '+':
        s->flags.plus = 1;
        break;
      case ' ':
        s->flags.space = 1;
        break;
      case '#':
        s->flags.sharp = 1;
        break;
      case '0':
        s->flags.zero = 1;
        break;
      default:
        exit = true;
        (*format)--;
    }
    (*format)++;
  }
  return 0;
}
int spec_reproc(s21_specifiers *s) {
  if (s->flags.minus ||
      (s->precisions > -1 && (s21_strchr("iuxXod", s->types))))  // !! prec > 0
    s->flags.zero = 0;
  if (s->flags.plus) s->flags.space = 0;
  if (s21_strchr("cdius", s->types)) s->flags.sharp = 0;

  if (s->precisions == -1) {
    switch (s->types) {
      case 'a':
      case 'A':
        s->precisions = 13;
        break;
      case 'd':
      case 'i':
      case 'o':
      case 'u':
      case 'x':
      case 'X':
        s->precisions = 1;
        break;
      case 'e':
      case 'E':
      case 'f':
      case 'F':
      case 'G':
      case 'g':
        s->precisions = 6;
        break;
    }
  } else if (s->precisions == -2 && s21_strchr("eEfF", s->types))
    s->precisions = 0;
  if ((s->types == 'G' || s->types == 'g') && s->precisions == 0)
    s->precisions = 1;
  if (s->types == 'p')
    s->flags.plus = s->flags.sharp = s->flags.space = s->flags.zero = 0;
  return 0;
}

int insertFormatedData(char **buffer, s21_specifiers *s, va_list *vaList) {
  int something = 12345;
  if (s21_strchr("diouxX", s->types)) {
    if ((s->lengths == 'l'))  // || s->lengths == 'L' according microsoft
      *buffer = printb_d(*buffer, va_arg(*vaList, unsigned long int), s);
    else if (s->lengths == 'h')
      *buffer = printb_d(
          *buffer, (unsigned long int)va_arg(*vaList, unsigned int), s);  //
    else
      *buffer =
          printb_d(*buffer, (unsigned long int)va_arg(*vaList, unsigned int),
                   s);  //(long int)

  } else if (s->types == 'c') {
    if ((s->lengths == 'l'))
      *buffer = printb_wc(*buffer, va_arg(*vaList, int),
                          s);  //'wchar_t {aka short unsigned int}' is promoted
                               // to 'int' when passed through '...'
    else
      *buffer =
          printb_c(*buffer, va_arg(*vaList, int),
                   s);  //'char' is promoted to 'int' when passed through '...'

  } else if (s->types == 's') {
    if ((s->lengths == 'l'))
      *buffer = printb_ws(*buffer, va_arg(*vaList, wchar_t *), s);
    else
      *buffer = printb_s(*buffer, va_arg(*vaList, char *), s);

  } else if (s->types == 'f') {
    if (s->lengths == 'L')
      *buffer = printb_f(*buffer, va_arg(*vaList, long double), s);
    else
      *buffer = printb_f(*buffer, va_arg(*vaList, double), s);
  } else if (s21_strchr("eEgG", s->types)) {
    if (s->lengths == 'L')
      *buffer = printb_e(*buffer, va_arg(*vaList, long double), s);
    else
      *buffer = printb_e(*buffer, (long double)va_arg(*vaList, double), s);
  } else if (s->types == 'p') {
    *buffer = printb_p(*buffer, va_arg(*vaList, void *), s);
  }
  return something;
}

char *s21_widthFlag(char *digit_str, s21_specifiers *s) {
  s21_size_t digit_len = s21_strlen(digit_str);
  if (digit_len >= s->widths) return digit_str;

  s21_size_t len_w = s->widths - s21_strlen(digit_str);
  char *str_w = calloc(len_w + 1, sizeof(char));

  s21_memset(str_w, (s->flags.zero) ? '0' : ' ', len_w);
  s21_size_t insert_pos = 0;
  if ((s->flags.minus))
    insert_pos = digit_len;
  else if ((digit_str[0] == '-' || digit_str[0] == '+' ||
            digit_str[0] == ' ') &&
           (s->flags.zero))
    insert_pos = 1;
  char *insertion = s21_insert(digit_str, str_w, insert_pos);
  if (insertion) s21_strcpy(digit_str, insertion);

  free(str_w);

  return digit_str;
}
char *s21_precFlag(char *digit_str, s21_specifiers *s) {
  s21_size_t digit_len = s21_strlen(digit_str);
  int sign = (digit_str[0] == '-' || digit_str[0] == '+' || digit_str[0] == ' ')
                 ? 1
             : (digit_str[1] == 'x' || digit_str[1] == 'X') ? 2
                                                            : 0;
  if (digit_len - sign >= (s21_size_t)(*s).precisions) return digit_str;

  s21_size_t len_p = s->precisions - s21_strlen(digit_str) + sign;
  char *str_p = calloc(len_p + 1, sizeof(char));

  s21_memset(str_p, '0', len_p);
  s21_size_t insert_pos = sign;
  char *insertion = s21_insert(digit_str, str_p, insert_pos);
  if (insertion) s21_strcpy(digit_str, insertion);

  free(str_p);

  return digit_str;
}

char *printb_s(char *dest, char *value, s21_specifiers *s) {
  char tmp_str[S21_BUFF_SIZE] = {0};
  s21_strcpy(tmp_str, value);
  s21_size_t val_len = s21_strlen(tmp_str);
  if (s->precisions >= 0 && s->precisions < (int)val_len) {
    tmp_str[s->precisions] = '\0';
    val_len = s->precisions;
  }

  if (s->widths > val_len) s21_widthFlag(tmp_str, s);
  s21_strcpy(dest, tmp_str);
  dest += s21_strlen(tmp_str);
  return dest;
}

char *printb_ws(char *dest, wchar_t *value, s21_specifiers *s) {
  char tmp_str[S21_BUFF_SIZE] = {0};
  s21_size_t writed_sz = 0;
  if (s->types == 'c') {  // ignore precision, convert 1 sym
    s->precisions = -1;
    printf("c\n");
    writed_sz = wctomb(tmp_str, *value);
  } else
    writed_sz = wcstombs(tmp_str, value, S21_BUFF_SIZE - 1);
  if (writed_sz != (s21_size_t)(-1)) {
    dest = printb_s(dest, tmp_str, s);
  }
  return dest;
}

char *printb_c(char *dest, int value, s21_specifiers *s) {
  // all flags ignored but '-'; presicion ignored
  if (s->widths > 1 && !(s->flags.minus)) {
    s21_memset(dest, ' ', s->widths - 1);
    dest += s->widths - 1;
  }
  *dest = (char)value;
  dest++;
  if (s->widths > 1 && (s->flags.minus)) {
    s21_memset(dest, ' ', s->widths - 1);
    dest += s->widths - 1;
  }
  return dest;
}

char *printb_wc(char *dest, wchar_t value, s21_specifiers *s) {
  dest = printb_ws(dest, &value, s);

  return dest;
}

char *printb_p(char *dest, void *value, s21_specifiers *s) {
  if (value == 0) {
    s21_strcpy(dest, "(nil)");
    dest += 5;
  } else {
    s->lengths = 'l';
    s->flags.sharp = 1;
    s->types = 'x';
    s->precisions = 1;  // sizeof(void*) * 2;
    dest = printb_d(dest, (unsigned long)value, s);
  }

  return dest;
}

/*!
 * @brief //int,short int -> int,short int inside of long int countainer
 * @param pointer to long int we work with
 * @param sizeChar size of int we shold truncate to: h - short int, \0 - int
 * ,L,l - long int(no changes)
 */
int lenghtSpecifierHandler(unsigned long int *value, s21_specifiers *s) {
  s21_size_t bits_to_keep = sizeof(long int) * 8;
  if (s->lengths ==
      '\0') {  // L only applies to floating point specifiers − e, E, f, g and G
    bits_to_keep = sizeof(int) * 8;
    // size = sizeof(int);
  } else if (s->lengths == 'h')
    bits_to_keep = sizeof(short int) * 8;
  long int mask = 0;
  long int bite = 1;
  for (s21_size_t i = 0; i < bits_to_keep; i++) {
    mask |= bite;
    bite = bite << 1;
  }
  *value &= mask;
  if (s->types == 'd' || s->types == 'i') {  // if signed int
    bite = 1 << (bits_to_keep - 1);
    if (bite & *value)  // if negative
      *value |= bite | ~mask;
  }

  return 0;
}
int s21_handle_NaN_INF(char *buf, int sign, long double value,
                       s21_specifiers *s) {
  int res = 0;
  if (S21_ISNAN(value)) {
    s21_strcpy(&buf[sign], "nan");
    s->flags.zero = 0;
    res = 10;
  } else if (S21_ISINF(value)) {
    s21_strcpy(&buf[sign], "inf");
    s->flags.zero = 0;
    res = 1;
  }
  if (res && s21_strchr("FEG", s->types)) {
    s21_strcpy(buf, s21_to_upper(buf));
  }
  return res;
}
char *printb_f(char *dest, long double value, s21_specifiers *s) {
  char tmp_digit[S21_BUFF_SIZE] = {0};

  int sign = 0;
  if (signbit(value)) {
    sign = 1;
    *tmp_digit = '-';
    value = fabsl(value);
  } else if (s->flags.plus) {
    sign = 1;
    *tmp_digit = '+';
  } else if (s->flags.space) {
    sign = 1;
    *tmp_digit = ' ';
  }

  if (!s21_handle_NaN_INF(tmp_digit, sign, value, s)) {
    s21_dtoa(value, &tmp_digit[sign], s->precisions);
    if (s->flags.sharp && !s->precisions) s21_strncat(tmp_digit, ".", 1);
  }
  if (s->widths > s21_strlen(tmp_digit)) s21_widthFlag(tmp_digit, s);

  s21_strcpy(dest, tmp_digit);  //,s21_strlen(tmp_digit));
  dest += s21_strlen(tmp_digit);

  return dest;
}

/**
 * @todo fix nan and inf
 * @todo fix gG precision
 */
char *printb_e(char *dest, long double value, s21_specifiers *s) {
  char tmp[S21_BUFF_SIZE] = {0};
  char format_str_proto[12] = ".*Lf";  //
  char format_str_e[12] = "e%+0.2d";
  char format_str[50] = {0};
  long double value_init = value;
  int sign = signbit(value);
  bool printAsE = 1;
  int pow = 0;

  value = fabsl(value);
  if (s->types == 'E' || s->types == 'G') format_str_e[0] = 'E';
  if (!s21_handle_NaN_INF(tmp, sign, value, s)) {
    if (value != 0.0L) {
      while (value >= 10.0L) {
        value /= 10.0L;
        pow++;
      }
      while (value < 1.0L) {
        value *= 10.0L;
        pow--;
      }
    }
    int round_to = ((s->types == 'G' || s->types == 'g') && s->precisions <= 2)
                       ? s->precisions - 1
                       : s->precisions;
    value = roundl(value * powl(10.0L, round_to));
    value = value / powl(10.0L, round_to);
    if (value >= 10.0L) {
      value /= 10.0L;
      pow++;
    } else if (value < 1.0L && value != 0.0L) {
      value *= 10.0L;
      pow--;
    }

    if (sign) value = -value;

    if (s->types == 'g' || s->types == 'G') {
      if (pow < -4 || pow >= s->precisions) {
        s->precisions -= 1;  // print as E

      } else {
        s->precisions -= (pow + 1);  // F
        printAsE = 0;
      }
    }

  } else {
    printAsE = 0;
  }

  s21_strncat(format_str, "%", 1);
  if (s->flags.plus) s21_strncat(format_str, "+", 1);
  if (s->flags.sharp) s21_strncat(format_str, "#", 1);
  if (s->flags.space) s21_strncat(format_str, " ", 1);

  if (!printAsE) {
    format_str_proto[4] = '\0';
    value = value_init;
  }

  s21_strncat(format_str, format_str_proto, s21_strlen(format_str_proto));
  s21_sprintf(tmp, format_str, s->precisions, value);

  // if (!printAsE & !s->flags.sharp)//truncate
  if ((s->types == 'G' || s->types == 'g') && !s->flags.sharp)  // truncate

  {
    char *dot_ptr = s21_strchr(tmp, '.');
    if (dot_ptr) s21_trim_R(tmp, "0");
  }

  if (printAsE) s21_sprintf(&tmp[s21_strlen(tmp)], format_str_e, pow);

  if (s->widths > s21_strlen(tmp)) s21_widthFlag(tmp, s);
  s21_strcpy(dest, tmp);
  dest += s21_strlen(tmp);
  return dest;
}

int s21_trim_R(char *src, const char *trStr) {
  if (!src) return 1;
  int src_end = s21_strlen(src) - 1;
  while (src_end > 0 && s21_strchr(trStr, src[src_end]) &&
         src[src_end--] != '.')
    ;  // src_end--;
  if (src[src_end] == '.') src_end--;
  src[src_end + 1] = '\0';
  return 0;
}

int s21_getRadix(char type) {
  return ((s21_strchr("xX", type)) ? 16 : (s21_strchr("o", type)) ? 8 : 10);
}
char *printb_d(char *dest, unsigned long value, s21_specifiers *s) {
  char tmp_digit[S21_BUFF_SIZE];

  lenghtSpecifierHandler(&value, s);
  long s_value;  // signed value
  int sign = 0;
  if (s->types == 'd' || s->types == 'i') {
    s21_memcpy(&s_value, &value, sizeof(unsigned long));
    if (s_value < 0) {
      sign = 1;
      *tmp_digit = '-';
      s_value = -s_value;
    } else if (s->flags.plus) {
      sign = 1;
      *tmp_digit = '+';
    } else if (s->flags.space) {
      sign = 1;
      *tmp_digit = ' ';
    }
    value = s_value;
  }
  int radix = s21_getRadix(s->types);
  s21_itoa(value, &tmp_digit[sign], radix);

  if (s->types == 'X') s21_strcpy(tmp_digit, s21_to_upper(tmp_digit));

  if (s->flags.sharp) {  //!!
    if (radix == 8) {
      s21_strcpy(tmp_digit, s21_insert(tmp_digit, "0", 0));
      sign = 1;
    } else if (radix == 16 && value != 0) {
      s21_strcpy(tmp_digit,
                 s21_insert(tmp_digit, ((s->types == 'X') ? "0X" : "0x"), 0));
      sign = 2;
      if (s->flags.zero &&
          s->widths >=
              (s21_size_t)sign) {  //!! is it works same way with all radix?
        s->precisions = s->widths - sign;
        s->widths = 0;
      }
    }
  }

  if (s->precisions == 0 && value == 0)
    tmp_digit[sign] = '\0';
  else if ((s21_size_t)s->precisions > s21_strlen(tmp_digit) - sign) {
    s21_precFlag(tmp_digit, s);
  }

  if (s->widths > s21_strlen(tmp_digit)) s21_widthFlag(tmp_digit, s);

  s21_strcpy(dest, tmp_digit);
  dest += s21_strlen(tmp_digit);

  return dest;
}

char *s21_dtoa(long double value, char *buf,
               int precision) {  // using math.modfl to split integer and
                                 // decimal parts of double
  char tmp[S21_BUFF_SIZE] = {0};
  char *buf_start = buf;
  long double decimal;  //,integer

  int sign = 0, i = 0;
  if (signbit(value)) {
    value = fabsl(value);
    sign = 1;
  }

  decimal = modfl(value, &value) * powl(10.0L, precision);
  decimal = roundl(decimal);
  if (decimal >= powl(10.0L, precision)) value += 1.0L;

  if (precision > 0) {
    i = 0;
    while (i < precision && i < S21_BUFF_SIZE - (buf - buf_start) - 1) {
      tmp[i] = '0' + ((int)fmodl(decimal, 10.0L));
      decimal /= 10.0;
      // buf++;
      i++;
    }
    tmp[i++] = '.';
  }
  do {
    tmp[i] = '0' + ((int)fmodl(value, 10.0L));
    value /= 10.0;
    i++;
  } while (value >= 1.0 && i < S21_BUFF_SIZE - 2);

  if (sign)
    tmp[i] = '-';
  else
    i--;

  while (i > -1) {
    *buf = tmp[i];
    buf++;
    i--;
  }

  *buf = '\0';
  return buf_start;
}

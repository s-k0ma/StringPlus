#include "../s21_string.h"

int parcer(const char *format, parcer_t *spec) {
  char flag[] = "-+ 0#";
  char width[] = "1234567890*";
  char accur[] = ".1234567890*";
  char lenght[] = "hlL";
  char specif[] = "cdieEfgGosuxXpn%";
  char *refer_pointer[5] = {flag, width, accur, lenght, specif};
  int counter = 0;
  int counter_buff;
  int ref_point_p = 0;
  int i = 0;
  while (*(format + counter) != 0) {
    if (*(format + counter) == '%' && ref_point_p == 0) {
      spec[i].spec_pos = counter;
      ++counter;
      for (ref_point_p = 0; ref_point_p < 5; ref_point_p++) {
        char *str = (char *)calloc(20, sizeof(char));
        search_spec(&counter_buff, &counter, format, refer_pointer[ref_point_p],
                    str, ref_point_p);
        switch (ref_point_p) {
          case 0: {
            s21_strcpy(spec[i].flag, str);
            break;
          }
          case 1: {
            if (s21_strchr(str, '*') != S21_NULL) {
              spec[i].width_arg_flag = 1;
            } else {
              spec[i].width_arg_flag = 0;
              int size = s21_strlen(str);
              spec[i].width = str_to_int(str, size);
            }
            break;
          }
          case 2: {
            if (s21_strchr(str, '*') != S21_NULL) {
              spec[i].accur_arg_flag = 1;
            } else {
              spec[i].accur = 0;
              spec[i].accur_arg_flag = 0;
              int size = s21_strlen(str);
              if (size == 0) {
                spec[i].accur = -1;
              } else {
                spec[i].accur = str_to_int(str, size);
              }
            }
            break;
          }
          case 3: {
            spec[i].lenght = str[0];
            break;
          }
          case 4: {
            spec[i].specif = str[0];
            break;
          }
        }
        free(str);
      }
      ref_point_p = 0;
      if (s21_strchr(specif, spec[i].specif) == S21_NULL) {
        spec[i].specif = '%';
      }
      spec[i].size_format = counter - spec[i].spec_pos;
      i++;
    } else {
      ++counter;
    }
  }
  return i;
}

void search_spec(int *counter_buff, int *counter, const char *format,
                 char *refer, char *str, int ref_point_p) {
  *counter_buff = *counter;
  *counter = check(*counter, format, refer, ref_point_p);
  test_output(*counter, *counter_buff, format, str);
}

int check(int counter, const char *str, const char *refer, int ref_point_p) {
  int i = 0;
  while (s21_strchr(refer, (int)*(str + counter)) != S21_NULL) {
    ++counter;
    i++;
    if (ref_point_p == 4 && i == 1) {
      break;
    }
  }
  return counter;
}

void test_output(int counter, int counter_buff, const char *format, char *str) {
  int i = 0;
  while (counter_buff < counter) {
    *(str + i) = *(format + counter_buff);
    ++counter_buff;
    i++;
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  int used_args = 0;
  parcer_t spec[20];
  int num_exp_args = parcer(format, spec);
  int size_src = s21_strlen(str);
  int j = 0;
  va_list list_args;
  va_start(list_args, format);
  for (int i = 0; i < num_exp_args && j < size_src; i++) {
    if (spec[i].specif == 'c') {
      spec[i].width = 1;
    }
    char *buff = (char *)calloc(size_src, sizeof(char));
    int k = 0;
    while (*(str + j) != ' ' && *(str + j) != '\n' && *(str + j) != '\t' &&
           j < size_src) {
      *(buff + k) = *(str + j);
      k++;
      if (spec[i].width != 0 && spec[i].width == k) {
        break;
      }
      j++;
    }
    j++;
    while (*(str + j) == ' ' || *(str + j) == '\n' || *(str + j) == '\t') {
      j++;
    }
    if (spec[i].width_arg_flag == 0) {
      if (spec[i].width == 0) {
        spec[i].width = s21_strlen(buff);
      }
      s21_size_t size = (s21_size_t)spec[i].width < s21_strlen(buff)
                            ? (s21_size_t)spec[i].width
                            : s21_strlen(buff);
      if (spec[i].specif == 'c') {
        str_to_ch(buff, &(spec[i]), list_args);
        used_args++;
      } else if (s21_strchr("duxXo", spec[i].specif) != S21_NULL) {
        int d;
        if (s21_strchr("xX", spec[i].specif) != S21_NULL) {
          d = 16;
        } else if (spec[i].specif == 'o') {
          d = 8;
        } else {
          d = 10;
        }
        hex_oct_dec_convert(buff, size, &(spec[i]), list_args, d);
        used_args++;
      } else if (spec[i].specif == 'i') {
        hex_oct_str_to_int(&(spec[i]), buff, list_args);
        used_args++;
      } else if (spec[i].specif == 'n') {
        int *n_arg = va_arg(list_args, int *);
        *n_arg = j - k - 2;
        if (*n_arg < 0) *n_arg = 0;
        used_args++;
      } else if (s21_strchr("eEfgG", spec[i].specif) != S21_NULL) {
        double_arg_to_str(buff, size, &(spec[i]), list_args);
        used_args++;
      } else if (spec[i].specif == 'p') {
        hex_oct_dec_convert(buff, size, &(spec[i]), list_args, 16);
        used_args++;
      }
    }
    free(buff);
  }
  va_end(list_args);
  return used_args;
}

int str_to_int(char *str, int size) {
  int sign = check_sign(&str, &size);
  int d = 0;
  for (int i = 0; i < size; i++) {
    if (*(str + i) >= '0' && *(str + i) <= '9') {
      d *= 10;
      d += (*(str + i) - '0');
    }
  }
  d *= sign;
  return d;
}

void hex_oct_str_to_int(parcer_t *spec, char *buff, va_list list_args) {
  int size =
      spec->width < (int)s21_strlen(buff) ? spec->width : (int)s21_strlen(buff);
  if (*buff == '0') {
    if (*(buff + 1) == 'x' || *(buff + 1) == 'X') {
      hex_oct_dec_convert(buff + 2, size - 2, spec, list_args, 16);
    } else {
      hex_oct_dec_convert(buff + 1, size - 1, spec, list_args, 8);
    }
  } else {
    hex_oct_dec_convert(buff, size, spec, list_args, 10);
  }
}

void hex_oct_dec_convert(char *buff, int size, parcer_t *spec,
                         va_list list_args, int s_s) {
  int_type int_val;
  unsigned long arg = 0;
  int sign = check_sign(&buff, &size);
  for (int i = 0; i < size; i++) {
    arg *= s_s;
    if (*(buff + i) >= '0' && *(buff + i) <= '9') {
      arg += (*(buff + i) - '0');
    } else if (*(buff + i) >= 'a' && *(buff + i) <= 'f') {
      arg += (*(buff + i) - 'W');
    } else if (*(buff + i) >= 'A' && *(buff + i) <= 'F') {
      arg += (*(buff + i) - '7');
    }
  }
  arg *= sign;
  if (s21_strchr("uxXo", spec->specif) != S21_NULL) {
    if (spec->lenght == 'l') {
      int_val.lu = va_arg(list_args, unsigned long *);
      *(int_val.lu) = (unsigned long)arg;
    } else if (spec->lenght == 'h') {
      int_val.hu = va_arg(list_args, unsigned short *);
      *(int_val.hu) = (unsigned short)arg;
    } else {
      int_val.u = va_arg(list_args, unsigned *);
      *(int_val.u) = (unsigned)arg;
    }
  } else if (s21_strchr("di", spec->specif) != S21_NULL) {
    if (spec->lenght == 'l') {
      int_val.ld = va_arg(list_args, long *);
      *(int_val.ld) = (long)arg;
    } else if (spec->lenght == 'h') {
      int_val.h = va_arg(list_args, short *);
      *(int_val.h) = (short)arg;
    } else {
      int_val.d = va_arg(list_args, int *);
      *(int_val.d) = (int)arg;
    }
  } else if (spec->specif == 'p') {
    void *p_arg = va_arg(list_args, void **);
    int_val.ld = p_arg;
    *(int_val.ld) = (long)arg;
  }
}

void double_arg_to_str(char *buff, int size, parcer_t *spec,
                       va_list list_args) {
  double_type doub_val;
  long double f_arg = 0;
  int left = 0;
  int sign = *buff == '-' ? -1 : 1;
  int i = 0;
  if (*buff == '-' || *buff == '+') {
    i++;
  }
  for (; i < size && *(buff + i) != '.'; i++) {
    left *= 10;
    left += (*(buff + i) - '0');
  }
  f_arg = left;
  int count_num = 0;
  int right = 0;
  if (i < size && *(buff + i) == '.') {
    for (++i; i < size && *(buff + i) != 'e' && *(buff + i) != 'E'; i++) {
      right *= 10;
      right += (*(buff + i) - '0');
      count_num++;
    }
  }
  f_arg += right / pow(10, count_num);
  if (i < size && (*(buff + i) == 'e' || *(buff + i) == 'E')) {
    i++;
    int st_sign = *(buff + i) == '-' ? -1 : 1;
    int st = 0;
    count_num = 0;
    for (++i; i < size && count_num < 2; i++) {
      st *= 10;
      st += (*(buff + i) - '0');
      count_num++;
    }
    f_arg *= pow(10, st * st_sign);
  }
  f_arg *= sign;
  if (spec->lenght == 'l') {
    doub_val.doub = va_arg(list_args, double *);
    *(doub_val.doub) = (double)f_arg;
  } else if (spec->lenght == 'L') {
    doub_val.l_doub = va_arg(list_args, long double *);
    *(doub_val.l_doub) = (long double)f_arg;
  } else {
    doub_val.f = va_arg(list_args, float *);
    *(doub_val.f) = (float)f_arg;
  }
}

void clean_str(char *str, int size_str) {
  if (size_str > 0) {
    for (int j = 0; j < size_str; j++) {
      *(str + j) = 0;
    }
  }
}

void str_to_ch(char *buff, parcer_t *spec, va_list list_arg) {
  char *ch;
  wchar_t *wch;
  if (spec->lenght == 'l') {
    wch = va_arg(list_arg, wchar_t *);
    *wch = (wchar_t)*buff;
  } else {
    ch = va_arg(list_arg, char *);
    *ch = *buff;
  }
}

int check_sign(char **str, int *size) {
  int sign = 1;
  if (**str == '-') {
    *str += 1;
    *size -= 1;
    sign = -1;
  }
  return sign;
}

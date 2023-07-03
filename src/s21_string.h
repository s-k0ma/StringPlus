#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define S21_TYPES_STR "cdieEfgGosuxXpn"
#define S21_FLAGS_STR "-+ #0"
#define S21_LENGH_STR "hlL"
#define HEX_SYM "+-0123456789abcdefXx"
#define OCT_SYM "+-01234567"
#define DEC_SYM "+-0123456789"

#define MAX_BUFFER_SIZE 10000
#define S21_BUFF_SIZE 4096  // sprintf max output is 512
#define S21_ISNAN(x) (!(x >= 0) && !(x < 0))
#define S21_ISINF(x) ((x == S21_INF) || (x == -S21_INF))
#define S21_INF __builtin_huge_valf()

#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;

typedef struct s21_specifier_flag {
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
} s21_specifier_flag;

typedef struct s21_specifiers {
  unsigned char types;
  s21_specifier_flag flags;
  unsigned int widths;
  int precisions;
  unsigned char lengths;
  unsigned int ss;  // spec start
  unsigned int se;  // spec end
  unsigned int size;
  unsigned int count;
  bool assignment_suppress;
} s21_specifiers;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_isspace(int c);

int s21_sprintf(char *buffer, const char *format, ...);
char *s21_strerror(int errnum);

long long int s21_atoi(const char *str_init, int radix);
char *s21_strcpy(char *dest, char *src);
int s21_sscanf(const char *buffer, const char *format, ...);
int read_format_str(const char *buffer, const char *format, va_list *vaList);
bool valid_specifier_finder(const char **format, va_list *vaList,
                            s21_specifiers *s, char mode);
s21_specifiers init_spec(void);
const char *write_integer(const char *buffer, s21_specifiers *s,
                          va_list *vaList, int radix, const char *available_sym,
                          bool *error);
const char *write_float(const char *buffer, s21_specifiers *s, va_list *vaList,
                        bool *error);
const char *write_str(const char *buffer, s21_specifiers *s, va_list *vaList);
const char *read_buffer(const char *buffer, s21_specifiers *s, va_list *vaList,
                        bool *error);
int s21_sprintf(char *buffer, const char *format, ...);
int parseFlags(const char **format, s21_specifiers *s);
int spec_reproc(s21_specifiers *s);
char *s21_itoa(unsigned long value, char *buf, int radix);
char *s21_dtoa(long double value, char *buf, int precision);
int insertFormatedData(char **buffer, s21_specifiers *s, va_list *vaList);
int s21_dump_to_buf(char **buffer, const char *format, va_list *vaList);
char *s21_strnpbrk(const char *str1, const char *str2);
char *printb_s(char *dest, char *value, s21_specifiers *s);
char *printb_c(char *dest, int value, s21_specifiers *s);
int s21_handle_NaN_INF(char *buf, int sign, long double value,
                       s21_specifiers *s);
char *printb_f(char *dest, long double value, s21_specifiers *s);
char *printb_d(char *dest, unsigned long int value, s21_specifiers *s);
int s21_strShiftR(char *str, int shift);
int s21_handle_NaN_INF(char *buf, int sign, long double value,
                       s21_specifiers *s);
char *printb_wc(char *dest, wchar_t value, s21_specifiers *s);
char *printb_p(char *dest, void *value, s21_specifiers *s);
char *printb_e(char *dest, long double value, s21_specifiers *s);
int s21_trim_R(char *src, const char *trStr);
char *printb_ws(char *dest, wchar_t *value, s21_specifiers *s);

char *s21_to_upper_stat(const char *str);
char *s21_to_lower_stat(const char *str);
char *s21_insert_stat(const char *src, const char *str, size_t start_index);
char *s21_trim_stat(const char *src, const char *trim_chars);

int s21_isCharContainedInStr(char c, const char *str);
void params(va_list *args, char **next, char spec, int size);
void mytoi(int *value, char *line, int size);
int seekdigit(char *line);
char *get_token(char *src, char *delims, char **next, int size);
char *trim_separators(char *src, char *separators);
s21_size_t contains_symbol(char *symbols, char symbol);
void *alloc_mem(size_t nbytes);
void *calloc_mem(size_t nelems, size_t elem_size);
#define alloc_str(x) ((char *)alloc_mem(x + 1))
typedef struct parcer_params {
  char flag[6];
  int width;
  int accur;
  char lenght;
  char specif;
  int width_arg_flag;
  int accur_arg_flag;
  int size_format;
  int spec_pos;
} parcer_t;
int parcer(const char *format, parcer_t *spec);
void search_spec(int *counter_buff, int *counter, const char *format,
                 char *refer, char *str, int ref_point_p);
int check(int counter, const char *str, const char *refer, int ref_point_p);
void test_output(int counter, int counter_buff, const char *format, char *str);
void sscanf_str_to_res(parcer_t *spec, char *src, va_list list_args);

typedef struct int_types {
  long *ld;
  int *d;
  short *h;
  unsigned long *lu;
  unsigned *u;
  unsigned short *hu;
} int_type;

typedef struct double_types {
  float *f;
  double *doub;
  long double *l_doub;
} double_type;
void clean_str(char *str, int size_str);
void double_arg_to_str(char *buff, int size, parcer_t *spec, va_list list_args);
void hex_oct_dec_convert(char *buff, int size, parcer_t *spec,
                         va_list list_args, int s_s);
void hex_oct_str_to_int(parcer_t *spec, char *buff, va_list list_args);
int str_to_int(char *str, int size);
void str_to_ch(char *buff, parcer_t *spec, va_list list_arg);
int check_sign(char **str, int *size);
// typedef struct parametrs {
//   int width;
// } params;

// void write(char current, char * buffer);
// void strAppend(char * str1, char * buffer);
// char* intToString(int num);
// char* unsignedIntToString(int num);
// char* doubleToString(double num);
// char* roundDoubleString(const char* numberString);

// typedef struct parametrs {
//   int width;
//   int width_star;
//   int width_check;
//   int precision_star;
//   int precision;
//   int precision_check;
//   int precision_check_cm_ochka;
//   int length_h;
//   int length_l;
//   int length_L;
//   int flag_minus;
//   int flag_plus;
//   int flag_null;
//   int flag_space;
//   int flag_lattice;
//   int check_point;
// } params;

// #endif
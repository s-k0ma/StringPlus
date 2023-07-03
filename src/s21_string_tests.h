#ifndef __SRC_HEADERS_S21_STRING_TESTS_H__
#define __SRC_HEADERS_S21_STRING_TESTS_H__

#include <check.h>
#include <limits.h>
#include <string.h>

#include "s21_string.h"

Suite *s21_memchr_test(void);
Suite *s21_strlen_test(void);
Suite *s21_memcmp_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strerror_test(void);
Suite *s21_strtok_test(void);
Suite *s21_strstr_test(void);
Suite *s21_strpbrk_test(void);
Suite *s21_to_upper_test(void);
Suite *s21_to_lower_test(void);
Suite *s21_insert_test(void);
Suite *s21_trim_test(void);
Suite *s21_strchr_test(void);
Suite *s21_memcpy_test(void);
Suite *s21_memset_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strncpy_test(void);
Suite *s21_strcspn_test(void);
Suite *s21_strrchr_test(void);
Suite *s21_sscanf_test_x(void);
Suite *s21_sscanf_c(void);
Suite *s21_test_sscanf_d(void);
Suite *s21_test_sscanf_empty(void);
Suite *s21_test_sscanf_i(void);
Suite *s21_test_sscanf_n(void);
Suite *s21_test_sscanf_o(void);
Suite *s21_test_sscanf_p(void);
Suite *s21_test_sscanf_real(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_signed(void);
Suite *test_sprintf_e(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_g(void);
Suite *test_sprintf_hex(void);
Suite *test_sprintf_HEX(void);
Suite *test_sprintf_signed_i(void);
Suite *test_sprintf_n(void);
Suite *test_sprintf_octal(void);
Suite *test_sprintf_percent(void);
Suite *test_sprintf_pointer(void);
Suite *test_sprintf_string(void);
Suite *test_sprintf_unsigned(void);
Suite *test_c_sharp_static(void);

#endif  //  __SRC_HEADERS_S21_STRING_TESTS_H__
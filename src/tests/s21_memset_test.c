#include "../s21_string_tests.h"

START_TEST(test_s21_memset_1) {
  char str[] = "Hello!";
  int c = 65;
  size_t n = 2;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str[] = "";
  int c = '\0';
  size_t n = 0;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str[] = "";
  int c = '\0';
  size_t n = 1;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(test_s21_memset_4) {
  char str[] = "Hello! World";
  int c = '\n';
  size_t n = 6;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(test_s21_memset_5) {
  char str[] = "Hello! World";
  int c = 13;
  size_t n = 6;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

Suite* s21_memset_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strchr_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_memset_1);
  tcase_add_test(tc_core, test_s21_memset_2);
  tcase_add_test(tc_core, test_s21_memset_3);
  tcase_add_test(tc_core, test_s21_memset_4);
  tcase_add_test(tc_core, test_s21_memset_5);

  suite_add_tcase(s, tc_core);
  return s;
}
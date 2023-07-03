#include "../s21_string_tests.h"

START_TEST(test_s21_strncat_1) {
  char dest[256] = "Hello, ";
  char src[256] = "World!";
  size_t n = 6;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char dest[256] = "Hello, ";
  char src[256] = "World!";
  size_t n = 3;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char dest[256] = "Hello, ";
  char src[256] = "World!";
  size_t n = 20;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char dest[256] = "Hello, ";
  char src[256] = "World!";
  size_t n = 0;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char dest[256] = "";
  char src[256] = "World!";
  size_t n = 4;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char dest[256] = "Hello! ";
  char src[256] = "";
  size_t n = 3;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_7) {
  char dest[256] = "";
  char src[256] = "";
  size_t n = 10;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncat_8) {
  char dest[256] = "programs \0 no programs";
  char src[256] = "\n";
  size_t n = 2;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

Suite* s21_strncat_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strncat_1);
  tcase_add_test(tc_core, test_s21_strncat_2);
  tcase_add_test(tc_core, test_s21_strncat_3);
  tcase_add_test(tc_core, test_s21_strncat_4);
  tcase_add_test(tc_core, test_s21_strncat_5);
  tcase_add_test(tc_core, test_s21_strncat_6);
  tcase_add_test(tc_core, test_s21_strncat_7);
  tcase_add_test(tc_core, test_s21_strncat_8);

  suite_add_tcase(s, tc_core);
  return s;
}
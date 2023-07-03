#include "../s21_string_tests.h"

START_TEST(test_s21_strncpy_1) {
  char dest[10] = "Hello!";
  char src[10] = "Hi!";
  size_t n = 3;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char dest[10] = "";
  char src[10] = " Hi!";
  size_t n = 3;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char dest[10] = "Hello!";
  char src[10] = "";
  size_t n = 3;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char dest[10] = "";
  char src[10] = "";
  size_t n = 3;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char dest[30] = "Hello!";
  char src[30] = "World! Hello!";
  size_t n = 20;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char dest[20] = "Hello!";
  char src[20] = "World! Hello!";
  size_t n = 0;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char dest[10] = "";
  char src[10] = "";
  size_t n = 0;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

Suite* s21_strncpy_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strchr_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strncpy_1);
  tcase_add_test(tc_core, test_s21_strncpy_2);
  tcase_add_test(tc_core, test_s21_strncpy_3);
  tcase_add_test(tc_core, test_s21_strncpy_4);
  tcase_add_test(tc_core, test_s21_strncpy_5);
  tcase_add_test(tc_core, test_s21_strncpy_6);
  tcase_add_test(tc_core, test_s21_strncpy_7);
  suite_add_tcase(s, tc_core);
  return s;
}
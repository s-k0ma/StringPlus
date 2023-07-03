#include "../s21_string_tests.h"

START_TEST(test_s21_to_upper_1) {
  char str[] = "qwerty123asdf";
  char up_str[] = "QWERTY123ASDF";
  char *s21_up_str = s21_to_upper(str);
  ck_assert_pstr_eq(s21_up_str, up_str);
  free(s21_up_str);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char str[] = "Hello! World!";
  char up_str[] = "HELLO! WORLD!";
  char *s21_up_str = s21_to_upper(str);
  ck_assert_pstr_eq(s21_up_str, up_str);
  free(s21_up_str);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char str[] = "";
  char up_str[] = "";
  char *s21_up_str = s21_to_upper(str);
  ck_assert_pstr_eq(s21_up_str, up_str);
  free(s21_up_str);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  char str[] = "upDATE@#!";
  char up_str[] = "UPDATE@#!";
  char *s21_up_str = s21_to_upper(str);
  ck_assert_pstr_eq(s21_up_str, up_str);
  free(s21_up_str);
}
END_TEST

Suite *s21_to_upper_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_to_upper_1);
  tcase_add_test(tc_core, test_s21_to_upper_2);
  tcase_add_test(tc_core, test_s21_to_upper_3);
  tcase_add_test(tc_core, test_s21_to_upper_4);
  suite_add_tcase(s, tc_core);
  return s;
}
#include "../s21_string_tests.h"

START_TEST(test_s21_to_lower_1) {
  char str[] = "QWERTY123ASDF";
  char low_str[] = "qwerty123asdf";
  char *s21_low_str = s21_to_lower(str);
  ck_assert_pstr_eq(s21_low_str, low_str);
  free(s21_low_str);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char str[] = "HELLO! World!";
  char low_str[] = "hello! world!";
  char *s21_low_str = s21_to_lower(str);
  ck_assert_pstr_eq(s21_low_str, low_str);
  free(s21_low_str);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char str[] = "";
  char low_str[] = "";
  char *s21_low_str = s21_to_lower(str);
  ck_assert_pstr_eq(s21_low_str, low_str);
  free(s21_low_str);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  char str[] = "12#WiN$$&";
  char low_str[] = "12#win$$&";
  char *s21_low_str = s21_to_lower(str);
  ck_assert_pstr_eq(s21_low_str, low_str);
  free(s21_low_str);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_to_lower_1);
  tcase_add_test(tc_core, test_s21_to_lower_2);
  tcase_add_test(tc_core, test_s21_to_lower_3);
  tcase_add_test(tc_core, test_s21_to_lower_4);
  suite_add_tcase(s, tc_core);
  return s;
}
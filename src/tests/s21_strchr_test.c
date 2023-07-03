#include "../s21_string_tests.h"

START_TEST(test_s21_strchr_1) {
  char* strch = strchr("Hello! World!", 'l');
  char* s21_strch = s21_strchr("Hello! World!", 'l');
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char* strch = strchr("", 'l');
  char* s21_strch = s21_strchr("", 'l');
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char* strch = strchr("Hello", '\0');
  char* s21_strch = s21_strchr("Hello", '\0');
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char* strch = strchr("Hello", 3);
  char* s21_strch = s21_strchr("Hello", 3);
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char* strch = strchr("Hello", 0);
  char* s21_strch = s21_strchr("Hello", 0);
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char* strch = strchr("Hello", -2);
  char* s21_strch = s21_strchr("Hello", -2);
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char* strch = strchr("Hello", 'r');
  char* s21_strch = s21_strchr("Hello", 'r');
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char* strch = strchr("", '\0');
  char* s21_strch = s21_strchr("", '\0');
  ck_assert_pstr_eq(strch, s21_strch);
}
END_TEST

Suite* s21_strchr_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strchr_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strchr_1);
  tcase_add_test(tc_core, test_s21_strchr_2);
  tcase_add_test(tc_core, test_s21_strchr_3);
  tcase_add_test(tc_core, test_s21_strchr_4);
  tcase_add_test(tc_core, test_s21_strchr_5);
  tcase_add_test(tc_core, test_s21_strchr_6);
  tcase_add_test(tc_core, test_s21_strchr_7);
  tcase_add_test(tc_core, test_s21_strchr_8);
  suite_add_tcase(s, tc_core);
  return s;
}
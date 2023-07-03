#include "../s21_string_tests.h"

START_TEST(test_s21_strrchr_1) {
  char* strrch = strrchr("Hello! World!", 'l');
  char* s21_strrch = s21_strrchr("Hello! World!", 'l');
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char* strrch = strrchr("", 'l');
  char* s21_strrch = s21_strrchr("", 'l');
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char* strrch = strrchr("Hello", '\0');
  char* s21_strrch = s21_strrchr("Hello", '\0');
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char* strrch = strrchr("Hello", 3);
  char* s21_strrch = s21_strrchr("Hello", 3);
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char* strrch = strrchr("Hello", 0);
  char* s21_strrch = s21_strrchr("Hello", 0);
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char* strrch = strrchr("Hello", -2);
  char* s21_strrch = s21_strrchr("Hello", -2);
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char* strrch = strrchr("Hello", 'r');
  char* s21_strrch = s21_strrchr("Hello", 'r');
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char* strrch = strrchr("", '\0');
  char* s21_strrch = s21_strrchr("", '\0');
  ck_assert_pstr_eq(strrch, s21_strrch);
}
END_TEST

Suite* s21_strrchr_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strchr_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strrchr_1);
  tcase_add_test(tc_core, test_s21_strrchr_2);
  tcase_add_test(tc_core, test_s21_strrchr_3);
  tcase_add_test(tc_core, test_s21_strrchr_4);
  tcase_add_test(tc_core, test_s21_strrchr_5);
  tcase_add_test(tc_core, test_s21_strrchr_6);
  tcase_add_test(tc_core, test_s21_strrchr_7);
  tcase_add_test(tc_core, test_s21_strrchr_8);

  suite_add_tcase(s, tc_core);
  return s;
}
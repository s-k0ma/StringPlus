#include "../s21_string_tests.h"

START_TEST(test_s21_strstr_1) {
  char haystack[] = "Hello, World!";
  char needle[] = "Hello, World!";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char haystack[] = "";
  char needle[] = "asdfqwer/.";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char haystack[] = "asdfqwer/.";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char haystack[] = "Hello, World!";
  char needle[] = "World";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite* s21_strstr_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strstr_1);
  tcase_add_test(tc_core, test_s21_strstr_2);
  tcase_add_test(tc_core, test_s21_strstr_3);
  tcase_add_test(tc_core, test_s21_strstr_4);
  tcase_add_test(tc_core, test_s21_strstr_5);

  suite_add_tcase(s, tc_core);
  return s;
}
#include "../s21_string_tests.h"

START_TEST(test_s21_strpbrk_1) {
  char str1[] = "Hello, World!";
  char str2[] = "e";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str1[] = "";
  char str2[] = "e";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str1[] = "asdf? qwer";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite* s21_strpbrk_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strpbrk_1);
  tcase_add_test(tc_core, test_s21_strpbrk_2);
  tcase_add_test(tc_core, test_s21_strpbrk_3);
  tcase_add_test(tc_core, test_s21_strpbrk_4);
  tcase_add_test(tc_core, test_s21_strpbrk_5);
  suite_add_tcase(s, tc_core);
  return s;
}
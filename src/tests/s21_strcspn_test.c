#include "../s21_string_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str1[] = "Hello! World!";
  char str2[] = "W";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str1[] = "Hello! World!";
  char str2[] = "Help";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str1[] = "";
  char str2[] = "Help";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str1[] = "Hello! World!";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char str1[] = "123456789";
  char str2[] = "Hi.";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite* s21_strcspn_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strncmp_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strcspn_1);
  tcase_add_test(tc_core, test_s21_strcspn_2);
  tcase_add_test(tc_core, test_s21_strcspn_3);
  tcase_add_test(tc_core, test_s21_strcspn_4);
  tcase_add_test(tc_core, test_s21_strcspn_5);
  tcase_add_test(tc_core, test_s21_strcspn_6);

  suite_add_tcase(s, tc_core);
  return s;
}
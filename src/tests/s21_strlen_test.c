#include "../s21_string_tests.h"

START_TEST(test_s21_strlen_1) {
  char src1[256] = "Hello, World! My name is Kostya\0";
  ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char src1[256] = "Hello, World! My name is \0Kostya";
  ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char src1[256] = "\0";
  ck_assert_int_eq(s21_strlen(src1), strlen(src1));
}
END_TEST

Suite* s21_strlen_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strlen_1);
  tcase_add_test(tc_core, test_s21_strlen_2);
  tcase_add_test(tc_core, test_s21_strlen_3);

  suite_add_tcase(s, tc_core);
  return s;
}
#include "../s21_string_tests.h"

START_TEST(strerror_test_1) {
  for (int i = 0; i < 200; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_test_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite* s21_strerror_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strerror_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, strerror_test_1);
  tcase_add_test(tc_core, strerror_test_2);
  suite_add_tcase(s, tc_core);
  return s;
}

#include "../s21_string_tests.h"

START_TEST(test_s21_memcpy_1) {
  char dest[20] = "Hello!";
  char src[20] = "Hi";
  size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char dest[20] = "Hello!";
  char src[20] = "Hi";
  size_t n = 5;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char dest[20] = "";
  char src[20] = "Hi";
  size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char dest[20] = "Hello";
  char src[20] = "";
  size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char dest[20] = "";
  char src[20] = "";
  size_t n = 0;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char dest[20] = "";
  char src[20] = "";
  size_t n = 2;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char dest[20] = "Hi";
  char src[20] = "Hello!";
  size_t n = 6;
  ck_assert_pstr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

Suite* s21_memcpy_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strchr_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_memcpy_1);
  tcase_add_test(tc_core, test_s21_memcpy_2);
  tcase_add_test(tc_core, test_s21_memcpy_3);
  tcase_add_test(tc_core, test_s21_memcpy_4);
  tcase_add_test(tc_core, test_s21_memcpy_5);
  tcase_add_test(tc_core, test_s21_memcpy_6);
  tcase_add_test(tc_core, test_s21_memcpy_7);

  suite_add_tcase(s, tc_core);
  return s;
}
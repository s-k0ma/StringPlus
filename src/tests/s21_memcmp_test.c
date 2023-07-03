#include "../s21_string_tests.h"

START_TEST(test_s21_memcmp_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char str1[] = "Hello";
  char str2[] = "Hellz";
  ck_assert_int_eq(memcmp(str1, str2, 5), s21_memcmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char str1[] = "abcd";
  char str2[] = "abcd";
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
}
END_TEST
START_TEST(test_s21_memcmp_4) {
  char str1[] = "Hello";
  char str2[] = "Hell";
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char str1[] = "Hello";
  char str2[] = "Hellz";
  ck_assert_int_eq(memcmp(str1, str2, 2), s21_memcmp(str1, str2, 2));
}
END_TEST

START_TEST(test_s21_memcmp_6) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
}
END_TEST

START_TEST(test_s21_memcmp_7) {
  char str1[] = "abcd";
  char str2[] = "abcf";
  ck_assert_int_eq(memcmp(str1, str2, 3), s21_memcmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_memcmp_8) {
  char str1[] = "123";
  char str2[] = "123";
  ck_assert_int_eq(memcmp(str1, str2, 3), s21_memcmp(str1, str2, 3));
}
END_TEST

Suite* s21_memcmp_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_memcmp_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_memcmp_1);
  tcase_add_test(tc_core, test_s21_memcmp_2);
  tcase_add_test(tc_core, test_s21_memcmp_3);

  tcase_add_test(tc_core, test_s21_memcmp_4);
  tcase_add_test(tc_core, test_s21_memcmp_5);
  tcase_add_test(tc_core, test_s21_memcmp_6);
  tcase_add_test(tc_core, test_s21_memcmp_7);
  tcase_add_test(tc_core, test_s21_memcmp_8);
  suite_add_tcase(s, tc_core);
  return s;
}
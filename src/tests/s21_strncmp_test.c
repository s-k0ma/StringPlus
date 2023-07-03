#include "../s21_string_tests.h"

START_TEST(test_s21_strncmp_1) {
  char strh[] = "Hello";
  char strh1[] = "Hello";
  ck_assert_int_eq(strncmp(strh, strh1, 5), s21_strncmp(strh, strh1, 5));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char strh[] = "Hello";
  char strhz[] = "Hellz";
  ck_assert_int_eq(strncmp(strh, strhz, 5), s21_strncmp(strh, strhz, 5));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char abcd[] = "abcd";
  char abcd1[] = "abcd";
  ck_assert_int_eq(strncmp(abcd, abcd1, 4), s21_strncmp(abcd, abcd1, 4));
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char strh[] = "Hello";
  char hell[] = "Hell";
  ck_assert_int_eq(strncmp(strh, hell, 4), s21_strncmp(strh, hell, 4));
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char strh[] = "Hello";
  char strhz[] = "Hellz";
  ck_assert_int_eq(strncmp(strh, strhz, 2), s21_strncmp(strh, strhz, 2));
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char emp[] = "";
  char em1[] = "";
  ck_assert_int_eq(strncmp(emp, em1, 0), s21_strncmp(emp, em1, 0));
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char abcf[] = "abcf";
  char abcd[] = "abcd";
  ck_assert_int_eq(strncmp(abcd, abcf, 3), s21_strncmp(abcd, abcf, 3));
}
END_TEST

/* START_TEST(test_s21_strncmp_8) {
  char str[] = "123";
  char str1[] = "123";
  ck_assert_int_eq(strncmp(str, str1, 5), s21_strncmp(str, str1, 5));
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char str[] = "123";
  char str1[] = "123";
  ck_assert_int_eq(strncmp(str, str1, 50), s21_strncmp(str, str1, 50));
}
END_TEST */

Suite* s21_strncmp_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("\033[97m\033[106ms21_strncmp_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strncmp_1);
  tcase_add_test(tc_core, test_s21_strncmp_2);
  tcase_add_test(tc_core, test_s21_strncmp_3);
  tcase_add_test(tc_core, test_s21_strncmp_4);
  tcase_add_test(tc_core, test_s21_strncmp_5);
  tcase_add_test(tc_core, test_s21_strncmp_6);
  tcase_add_test(tc_core, test_s21_strncmp_7);
  // tcase_add_test(tc_core, test_s21_strncmp_8);
  // tcase_add_test(tc_core, test_s21_strncmp_9);
  suite_add_tcase(s, tc_core);
  return s;
}

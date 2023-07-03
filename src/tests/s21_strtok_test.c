#include "../s21_string_tests.h"

START_TEST(test_s21_strtok_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  char delim[] = ",!";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
  while (str_1 != NULL) {
    str_1 = strtok(NULL, delim);
    str_2 = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(str_1, str_2);
  }
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str1[] = " Hello, World! My name is Vladimir! ";
  char str2[] = " Hello, World! My name is Vladimir! ";
  char delim[] = " ";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
  while (str_1 != NULL) {
    str_1 = strtok(NULL, delim);
    str_2 = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(str_1, str_2);
  }
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str1[] = " /Hello, / World! / My name / is Vladimir!/";
  char str2[] = " /Hello, / World! / My name / is Vladimir!/";
  char delim[] = " ,/";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
  while (str_1 != NULL) {
    str_1 = strtok(NULL, delim);
    str_2 = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(str_1, str_2);
  }
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = "";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str1[] = "asdf";
  char str2[] = "asdf";
  char delim[] = "";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
  while (str_1 != NULL) {
    str_1 = strtok(NULL, delim);
    str_2 = s21_strtok(NULL, delim);
    ck_assert_pstr_eq(str_1, str_2);
  }
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = ".a";
  char *str_1, *str_2;
  str_1 = strtok(str1, delim);
  str_2 = s21_strtok(str2, delim);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

Suite *s21_strtok_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_strtok_1);
  tcase_add_test(tc_core, test_s21_strtok_2);
  tcase_add_test(tc_core, test_s21_strtok_3);
  tcase_add_test(tc_core, test_s21_strtok_4);
  tcase_add_test(tc_core, test_s21_strtok_5);
  tcase_add_test(tc_core, test_s21_strtok_6);
  suite_add_tcase(s, tc_core);
  return s;
}
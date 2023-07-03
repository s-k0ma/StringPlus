#include "../s21_string_tests.h"

START_TEST(test_s21_insert_1) {
  char str[] = "Hello! World!";
  char ins_src[] = "Hello! ";
  char ins_str[] = "World!";
  int index = 7;
  char *s21_ins_str = s21_insert(ins_src, ins_str, index);
  ck_assert_pstr_eq(s21_ins_str, str);
  free(s21_ins_str);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char str[] = "My name is Vladimir!";
  char ins_src[] = "My name is !";
  char ins_str[] = "Vladimir";
  int index = 11;
  char *s21_ins_str = s21_insert(ins_src, ins_str, index);
  ck_assert_pstr_eq(s21_ins_str, str);
  free(s21_ins_str);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char str[] = "School 21";
  char ins_src[] = "21";
  char ins_str[] = "School ";
  int index = 0;
  char *s21_ins_str = s21_insert(ins_src, ins_str, index);
  ck_assert_pstr_eq(s21_ins_str, str);
  free(s21_ins_str);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char str[] = "";
  char ins_src[] = "";
  char ins_str[] = "";
  int index = 0;
  char *s21_ins_str = s21_insert(ins_src, ins_str, index);
  ck_assert_pstr_eq(s21_ins_str, str);
  free(s21_ins_str);
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[97m\033[106ms21_strlen_test\033[0m");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_s21_insert_1);
  tcase_add_test(tc_core, test_s21_insert_2);
  tcase_add_test(tc_core, test_s21_insert_3);
  tcase_add_test(tc_core, test_s21_insert_4);

  suite_add_tcase(s, tc_core);
  return s;
}
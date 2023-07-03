#include "../s21_string_tests.h"

START_TEST(sscanf_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_test_sscanf_empty(void) {
  Suite *s = suite_create("\033[97m\033[106ms21_sscanf_test_empty\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);

  suite_add_tcase(s, tc);
  return s;
}

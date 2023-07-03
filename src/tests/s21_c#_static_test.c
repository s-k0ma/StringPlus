#include "../s21_string_tests.h"

START_TEST(to_lower1) {
  // #line 480
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  char *str1;
  ck_assert_str_eq(str1 = s21_to_lower_stat(test),
                   "\" !!!! !!  azaz-01 !/:@[`{~   !!   !\"\t\n");
}
END_TEST

START_TEST(to_lower2) {
  // #line 484
  char *str1;
  char *test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(str1 = s21_to_lower_stat(test),
                   "abcdefghijklmnopqrstuvwxyz");
}
END_TEST

START_TEST(to_lower3) {
  // #line 488
  char *str1;
  char *test = "abCdEFghIjKlMNopqRStuvWxYZ";
  ck_assert_str_eq(str1 = s21_to_lower_stat(test),
                   "abcdefghijklmnopqrstuvwxyz");
}
END_TEST

START_TEST(to_lower4) {
  // #line 492
  char *str1;
  char *test = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(str1 = s21_to_lower_stat(test),
                   "abcdefghijklmnopqrstuvwxyz");

  // test for s21_to_upper_stat
}
END_TEST

START_TEST(to_upper1) {
  // #line 498
  char *str1;
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  ck_assert_str_eq(str1 = s21_to_upper_stat(test),
                   "\" !!!! !!  AZAZ-01 !/:@[`{~   !!   !\"\t\n");
}
END_TEST

START_TEST(to_upper2) {
  // #line 502
  char *str1;
  char *test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(str1 = s21_to_upper_stat(test),
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
END_TEST

START_TEST(to_upper3) {
  // #line 506
  char *str1;
  char *test = "abCdEFghIjKlMNopqRStuvWxYZ";
  ck_assert_str_eq(str1 = s21_to_upper_stat(test),
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
END_TEST

START_TEST(to_upper4) {
  // #line 510
  char *str1;
  char *test = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(str1 = s21_to_upper_stat(test),
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  // test for s21_to_insert
}
END_TEST

START_TEST(to_insert1) {
  // #line 516
  char *str1;
  char *str_insert_into = "012345";
  char *str_to_insert = "BBB";
  char result[70] =
      "BBB012345-0BBB12345-01BBB2345-012BBB345-0123BBB45-01234BBB5-012345BBB";
  for (int i = 1; i < 7; i++) {
    result[(i * 10) - 1] = '\0';
  }
  for (size_t i = 0; i <= strlen(str_insert_into) + 1; i++) {
    //(strlen(str_insert_into) + strlen(str_to_insert) + 1)
    str1 = s21_insert_stat(str_insert_into, str_to_insert, i);
    if (i != 7)
      ck_assert_str_eq(str1, (result + i * 10));
    else
      ck_assert_ptr_null(str1);
  }

  // test for s21_to_trim
}
END_TEST

START_TEST(trim1) {
  // #line 534
  char *str1;
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "azAZ-01 !/:@[`{~");
}
END_TEST

START_TEST(trim2) {
  // #line 540
  char *str1;
  char *test = "    ";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "");
}
END_TEST

START_TEST(trim3) {
  // #line 544
  char *str1;
  char *test = "a    ";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "a");
}
END_TEST

START_TEST(trim4) {
  // #line 549
  char *str1;
  char *test = "  a  ";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "a");
}
END_TEST

START_TEST(trim5) {
  // #line 554
  char *str1;
  char *test = "    a";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "a");
}
END_TEST

START_TEST(trim6) {
  // #line 559
  char *str1;
  char *test = "a    a";
  ck_assert_str_eq(str1 = s21_trim_stat(test, " !\"\t\n"), "a    a");
  ck_assert_ptr_eq(str1, test);
}
END_TEST

Suite *test_c_sharp_static(void) {
  Suite *s = suite_create("\033[97m\033[106ms21_ssprintf_test\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, to_lower1);
  tcase_add_test(tc, to_lower2);
  tcase_add_test(tc, to_lower3);
  tcase_add_test(tc, to_lower4);
  tcase_add_test(tc, to_upper1);
  tcase_add_test(tc, to_upper2);
  tcase_add_test(tc, to_upper3);
  tcase_add_test(tc, to_upper4);
  tcase_add_test(tc, to_insert1);
  tcase_add_test(tc, trim1);
  tcase_add_test(tc, trim2);
  tcase_add_test(tc, trim3);
  tcase_add_test(tc, trim4);
  tcase_add_test(tc, trim5);
  tcase_add_test(tc, trim6);

  suite_add_tcase(s, tc);
  return s;
}

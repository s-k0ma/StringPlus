#include "../s21_string_tests.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c Test % -10c Test %-lc";
  int a = 74;
  int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[100];
  char str2[100];  //%lc Test %llc Test %hc Test %hhc
  char *str3 = "%c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(to_lower1) {
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  char *str1;
  ck_assert_str_eq(str1 = s21_to_lower(test),
                   "\" !!!! !!  azaz-01 !/:@[`{~   !!   !\"\t\n");
}
END_TEST

START_TEST(to_lower2) {
  char *str1;
  char *test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(str1 = s21_to_lower(test), "abcdefghijklmnopqrstuvwxyz");
}
END_TEST

START_TEST(to_lower3) {
  char *str1;
  char *test = "abCdEFghIjKlMNopqRStuvWxYZ";
  ck_assert_str_eq(str1 = s21_to_lower(test), "abcdefghijklmnopqrstuvwxyz");
}
END_TEST

START_TEST(to_lower4) {
  char *str1;
  char *test = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(str1 = s21_to_lower(test), "abcdefghijklmnopqrstuvwxyz");

  // test for s21_to_upper
}
END_TEST

START_TEST(to_upper1) {
  char *str1;
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  ck_assert_str_eq(str1 = s21_to_upper(test),
                   "\" !!!! !!  AZAZ-01 !/:@[`{~   !!   !\"\t\n");
}
END_TEST

START_TEST(to_upper2) {
  char *str1;
  char *test = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(str1 = s21_to_upper(test), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
END_TEST

START_TEST(to_upper3) {
  char *str1;
  char *test = "abCdEFghIjKlMNopqRStuvWxYZ";
  ck_assert_str_eq(str1 = s21_to_upper(test), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
END_TEST

START_TEST(to_upper4) {
  char *str1;
  char *test = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(str1 = s21_to_upper(test), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  // test for s21_to_insert
}
END_TEST

START_TEST(to_insert1) {
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
    str1 = s21_insert(str_insert_into, str_to_insert, i);
    if (i != 7)
      ck_assert_str_eq(str1, (result + i * 10));
    else
      ck_assert_ptr_null(str1);
  }

  // test for s21_to_trim
}
END_TEST

START_TEST(trim1) {
  char *str1;
  char *test = "\" !!!! !!  azAZ-01 !/:@[`{~   !!   !\"\t\n";
  ck_assert_str_eq(str1 = s21_trim(test, " !\"\t\n"), "azAZ-01 !/:@[`{~");
}
END_TEST

START_TEST(trim2) {
  char *str1;
  char *test = "    ";
  ck_assert_str_eq(str1 = s21_trim(test, " !\"\t\n"), "");
}
END_TEST

START_TEST(trim3) {
  char *str1;
  char *test = "a    ";
  ck_assert_str_eq(str1 = s21_trim(test, " !\"\t\n"), "a");
}
END_TEST

START_TEST(trim4) {
  char *str1;
  char *test = "  a  ";
  ck_assert_str_eq(str1 = s21_trim(test, " !\"\t\n"), "a");
}
END_TEST

START_TEST(trim5) {
  char *str1;
  char *test = "    a";
  ck_assert_str_eq(str1 = s21_trim(test, " !\"\t\n"), "a");
}
END_TEST

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("\033[97m\033[106ms21_ssprintf_test\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_c);
  tcase_add_test(tc, sprintf_2_c);
  tcase_add_test(tc, sprintf_3_c);
  tcase_add_test(tc, sprintf_4_c);
  tcase_add_test(tc, sprintf_5_c);
  tcase_add_test(tc, sprintf_7_c);
  tcase_add_test(tc, sprintf_9_c);
  tcase_add_test(tc, sprintf_10_c);
  tcase_add_test(tc, sprintf_11_c);
  tcase_add_test(tc, sprintf_12_c);
  tcase_add_test(tc, sprintf_13_c);
  tcase_add_test(tc, sprintf_14_c);
  tcase_add_test(tc, sprintf_16_c);
  tcase_add_test(tc, sprintf_19_c);
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
  // tcase_add_test(tc, sprintf_20_c);
  // tcase_add_test(tc, sprintf_21_c);

  suite_add_tcase(s, tc);
  return s;
}

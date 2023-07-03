#include "../s21_string_tests.h"

void s21_Srunner(Suite** suite);

int main(void) {
  printf("\n\n \033[97m\033[106m|| FUNCTIONS||\033[0m \n\n");
  Suite* suite_20_func[] = {s21_memchr_test(),
                            s21_strlen_test(),
                            s21_strncmp_test(),
                            s21_memcmp_test(),
                            s21_strerror_test(),
                            s21_strtok_test(),
                            s21_strstr_test(),
                            s21_strpbrk_test(),
                            s21_to_upper_test(),
                            s21_to_lower_test(),
                            s21_insert_test(),
                            s21_trim_test(),
                            s21_strchr_test(),
                            s21_memcpy_test(),
                            s21_memset_test(),
                            s21_strncat_test(),
                            s21_strncpy_test(),
                            s21_strcspn_test(),
                            s21_strrchr_test(),
                            s21_sscanf_test_x(),
                            s21_test_sscanf_d(),
                            s21_test_sscanf_empty(),
                            s21_test_sscanf_i(),
                            s21_test_sscanf_o(),
                            s21_test_sscanf_p(),
                            s21_test_sscanf_real(),
                            test_sprintf_c(),
                            test_sprintf_signed(),
                            test_sprintf_e(),
                            test_sprintf_f(),
                            test_sprintf_g(),
                            test_sprintf_hex(),
                            test_sprintf_HEX(),
                            test_sprintf_signed_i(),
                            test_sprintf_octal(),
                            test_sprintf_percent(),
                            test_sprintf_pointer(),
                            test_sprintf_string(),
                            test_sprintf_unsigned(),
                            test_c_sharp_static(),
                            NULL};
  s21_Srunner(suite_20_func);
}

void s21_Srunner(Suite** suite) {
  /*   for(int i = 0; i < 19; i++){
      SRunner* suite_runner = srunner_create(suite[i]);
      srunner_run_all(suite_runner, CK_NORMAL);
      srunner_free(suite_runner);
    }

   */
  for (int i = 0; suite[i];
       i++) {  // while suite is not NULL; last member of suites array is NULL
    SRunner* suite_runner = srunner_create(suite[i]);
    srunner_run_all(suite_runner, CK_NORMAL);
    srunner_free(suite_runner);
  }
}
#include "math_tests.h"

int main() {
  setenv("CK_DEFAULT_TIMEOUT", "0.1", 1);
  SRunner *s21_math_runner = srunner_create(abs_suite());
  srunner_add_suite(s21_math_runner, acos_suite());
  srunner_add_suite(s21_math_runner, asin_suite());
  srunner_add_suite(s21_math_runner, atan_suite());
  srunner_add_suite(s21_math_runner, ceil_suite());
  srunner_add_suite(s21_math_runner, cos_suite());
  srunner_add_suite(s21_math_runner, exp_suite());
  srunner_add_suite(s21_math_runner, fabs_suite());
  srunner_add_suite(s21_math_runner, floor_suite());
  srunner_add_suite(s21_math_runner, fmod_suite());
  srunner_add_suite(s21_math_runner, log_suite());
  srunner_add_suite(s21_math_runner, pow_suite());
  srunner_add_suite(s21_math_runner, sin_suite());
  srunner_add_suite(s21_math_runner, sqrt_suite());
  srunner_add_suite(s21_math_runner, tan_suite());

  int failed = 0;
  // srunner_run_all(s21_math_runner, CK_ENV);
  srunner_run_tagged(s21_math_runner, NULL, NULL, TEST_TAGS, NULL, CK_SILENT);
  srunner_print(s21_math_runner, VERB_MODE);
  failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);
  unsetenv("CK_DEFAULT_TIMEOUT");
  printf("\nПровалено %d тестов..\n", failed);
  return 0;
}
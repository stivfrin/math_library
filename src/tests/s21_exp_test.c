#include "math_tests.h"

START_TEST(exp_fract) {
  double samples_exp[] = SAMPLES_FRACT;
  double x = samples_exp[_i];
  long double reference = 0;
  NICE_PRINT(exp, fract)
  FILL_TEST(exp(x), s21_exp(x))
}
END_TEST

START_TEST(exp_bad) {
  double samples_exp[] = SAMPLES_BAD;
  double x = samples_exp[_i];
  long double reference = 0;
  NICE_PRINT(exp, bad)
  FILL_TEST(exp(x), s21_exp(x))
}
END_TEST

START_TEST(exp_int) {
  double samples_exp[] = SAMPLES_INT;
  double x = samples_exp[_i];
  long double reference = 0;
  NICE_PRINT(exp, int)
  FILL_TEST(exp(x), s21_exp(x))
}
END_TEST

Suite* exp_suite(void) {
  Suite* suite = suite_create("exp");
  TCase* exp_tcase = tcase_create("exp_case");

  tcase_add_loop_test(exp_tcase, exp_fract, 0, 10);
  tcase_add_loop_test(exp_tcase, exp_bad, 0, 6);
  tcase_add_loop_test(exp_tcase, exp_int, 0, 10);

  tcase_set_tags(exp_tcase, "exp all");
  suite_add_tcase(suite, exp_tcase);
  return suite;
}
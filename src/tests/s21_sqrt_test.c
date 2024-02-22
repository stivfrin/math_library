#include "math_tests.h"

START_TEST(sqrt_int) {
  double samples_sqrt[] = SAMPLES_INT;
  double x = samples_sqrt[_i];
  long double reference = 0;
  NICE_PRINT(sqrt, int)
  FILL_TEST(sqrt(x), s21_sqrt(x))
}
END_TEST

START_TEST(sqrt_fract) {
  double samples_sqrt[] = SAMPLES_FRACT;
  double x = samples_sqrt[_i];
  long double reference = 0;
  NICE_PRINT(sqrt, fract)
  FILL_TEST(sqrt(x), s21_sqrt(x))
}
END_TEST

START_TEST(sqrt_bad) {
  double samples_sqrt[] = SAMPLES_BAD;
  double x = samples_sqrt[_i];
  long double reference = 0;
  NICE_PRINT(sqrt, bad)
  FILL_TEST(sqrt(x), s21_sqrt(x))
}
END_TEST

Suite* sqrt_suite(void) {
  Suite* suite = suite_create("sqrt");
  TCase* sqrt_tcase = tcase_create("sqrt_case");

  tcase_add_loop_test(sqrt_tcase, sqrt_int, 0, 10);
  tcase_add_loop_test(sqrt_tcase, sqrt_fract, 0, 10);
  tcase_add_loop_test(sqrt_tcase, sqrt_bad, 0, 6);

  tcase_set_tags(sqrt_tcase, "sqrt all");
  suite_add_tcase(suite, sqrt_tcase);
  return suite;
}
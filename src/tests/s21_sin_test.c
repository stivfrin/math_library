#include "math_tests.h"

START_TEST(sin_fract) {
  double samples_sin[] = SAMPLES_FRACT;
  double x = samples_sin[_i];
  long double reference = 0;
  NICE_PRINT(sin, fract)
  FILL_TEST(sin(x), s21_sin(x))
}
END_TEST

START_TEST(sin_bad) {
  double samples_sin[] = SAMPLES_BAD;
  double x = samples_sin[_i];
  long double reference = 0;
  NICE_PRINT(sin, bad)
  FILL_TEST(sin(x), s21_sin(x))
}
END_TEST

START_TEST(sin_trig) {
  double samples_sin[] = SAMPLES_TRIG;
  double x = samples_sin[_i];
  long double reference = 0;
  NICE_PRINT(sin, trig)
  FILL_TEST(sin(x), s21_sin(x))
}
END_TEST

Suite* sin_suite(void) {
  Suite* suite = suite_create("sin");
  TCase* sin_tcase = tcase_create("sin_case");

  tcase_add_loop_test(sin_tcase, sin_fract, 0, 10);
  tcase_add_loop_test(sin_tcase, sin_bad, 0, 6);
  tcase_add_loop_test(sin_tcase, sin_trig, 0, 6);

  tcase_set_tags(sin_tcase, "sin all");
  suite_add_tcase(suite, sin_tcase);
  return suite;
}
#include "math_tests.h"

START_TEST(ceil_fract) {
  double samples_ceil[] = SAMPLES_FRACT;
  double x = samples_ceil[_i];
  long double reference = 0;
  NICE_PRINT(ceil, fract)
  FILL_TEST(ceil(x), s21_ceil(x))
}
END_TEST

START_TEST(ceil_bad) {
  double samples_ceil[] = SAMPLES_BAD;
  double x = samples_ceil[_i];
  long double reference = 0;
  NICE_PRINT(ceil, bad)
  FILL_TEST(ceil(x), s21_ceil(x))
}
END_TEST

Suite* ceil_suite(void) {
  Suite* suite = suite_create("ceil");
  TCase* ceil_tcase = tcase_create("ceil_case");

  tcase_add_loop_test(ceil_tcase, ceil_fract, 0, 10);
  tcase_add_loop_test(ceil_tcase, ceil_bad, 0, 6);

  tcase_set_tags(ceil_tcase, "ceil all");
  suite_add_tcase(suite, ceil_tcase);
  return suite;
}
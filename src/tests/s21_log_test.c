#include "math_tests.h"

START_TEST(log_fract) {
  double samples_log[] = SAMPLES_FRACT;
  double x = samples_log[_i];
  long double reference = 0;
  NICE_PRINT(log, fract)
  FILL_TEST(log(x), s21_log(x))
}
END_TEST

START_TEST(log_bad) {
  double samples_log[] = SAMPLES_BAD;
  double x = samples_log[_i];
  long double reference = 0;
  NICE_PRINT(log, bad)
  FILL_TEST(log(x), s21_log(x))
}
END_TEST

Suite* log_suite(void) {
  Suite* suite = suite_create("log");
  TCase* log_tcase = tcase_create("log_case");

  tcase_add_loop_test(log_tcase, log_fract, 0, 10);
  tcase_add_loop_test(log_tcase, log_bad, 0, 6);

  tcase_set_tags(log_tcase, "log all");
  suite_add_tcase(suite, log_tcase);
  return suite;
}
#include "math_tests.h"

START_TEST(fabs_fract) {
  double samples_fabs[] = SAMPLES_FRACT;
  double x = samples_fabs[_i];
  long double reference = 0;
  NICE_PRINT(fabs, fract)
  FILL_TEST(fabs(x), s21_fabs(x))
}
END_TEST

START_TEST(fabs_bad) {
  double samples_fabs[] = SAMPLES_BAD;
  double x = samples_fabs[_i];
  long double reference = 0;
  NICE_PRINT(fabs, bad)
  FILL_TEST(fabs(x), s21_fabs(x))
}
END_TEST

Suite* fabs_suite(void) {
  Suite* suite = suite_create("fabs");
  TCase* fabs_tcase = tcase_create("fabs_case");

  tcase_add_loop_test(fabs_tcase, fabs_fract, 0, 10);
  tcase_add_loop_test(fabs_tcase, fabs_bad, 0, 6);

  tcase_set_tags(fabs_tcase, "fabs all");
  suite_add_tcase(suite, fabs_tcase);
  return suite;
}
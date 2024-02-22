#include "math_tests.h"

START_TEST(asin_fract) {
  double samples_asin[] = SAMPLES_FRACT;
  double x = samples_asin[_i];
  long double reference = 0;
  NICE_PRINT(asin, fract)
  FILL_TEST(asin(x), s21_asin(x))
}
END_TEST

START_TEST(asin_bad) {
  double samples_asin[] = SAMPLES_BAD;
  double x = samples_asin[_i];
  long double reference = 0;
  NICE_PRINT(asin, bad)
  FILL_TEST(asin(x), s21_asin(x))
}
END_TEST

START_TEST(asin_trig) {
  double samples_asin[] = SAMPLES_TRIG;
  double x = samples_asin[_i];
  long double reference = 0;
  NICE_PRINT(asin, trig)
  FILL_TEST(asin(x), s21_asin(x))
}
END_TEST

Suite* asin_suite(void) {
  Suite* suite = suite_create("asin");
  TCase* asin_tcase = tcase_create("asin_case");

  tcase_add_loop_test(asin_tcase, asin_fract, 0, 10);
  tcase_add_loop_test(asin_tcase, asin_bad, 0, 6);
  tcase_add_loop_test(asin_tcase, asin_trig, 0, 6);

  tcase_set_tags(asin_tcase, "asin all");
  suite_add_tcase(suite, asin_tcase);
  return suite;
}
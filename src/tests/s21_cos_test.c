#include "math_tests.h"

START_TEST(cos_fract) {
  double samples_cos[] = SAMPLES_FRACT;
  double x = samples_cos[_i];
  long double reference = 0;
  NICE_PRINT(cos, fract)
  FILL_TEST(cos(x), s21_cos(x))
}
END_TEST

START_TEST(cos_bad) {
  double samples_cos[] = SAMPLES_BAD;
  double x = samples_cos[_i];
  long double reference = 0;
  NICE_PRINT(cos, bad)
  FILL_TEST(cos(x), s21_cos(x))
}
END_TEST

START_TEST(cos_trig) {
  double samples_cos[] = SAMPLES_TRIG;
  double x = samples_cos[_i];
  long double reference = 0;
  NICE_PRINT(cos, trig)
  FILL_TEST(cos(x), s21_cos(x))
}
END_TEST

Suite* cos_suite(void) {
  Suite* suite = suite_create("cos");
  TCase* cos_tcase = tcase_create("cos_case");

  tcase_add_loop_test(cos_tcase, cos_fract, 0, 10);
  tcase_add_loop_test(cos_tcase, cos_bad, 0, 6);
  tcase_add_loop_test(cos_tcase, cos_trig, 0, 6);

  tcase_set_tags(cos_tcase, "cos all");
  suite_add_tcase(suite, cos_tcase);
  return suite;
}
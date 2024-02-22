#include "math_tests.h"

START_TEST(acos_fract) {
  double samples_acos[] = SAMPLES_FRACT;
  double x = samples_acos[_i];
  long double reference = 0;
  NICE_PRINT(acos, fract)
  FILL_TEST(acos(x), s21_acos(x))
}
END_TEST

START_TEST(acos_bad) {
  double samples_acos[] = SAMPLES_BAD;
  double x = samples_acos[_i];
  long double reference = 0;
  NICE_PRINT(acos, bad)
  FILL_TEST(acos(x), s21_acos(x))
}
END_TEST

START_TEST(acos_trig) {
  double samples_acos[] = SAMPLES_TRIG;
  double x = samples_acos[_i];
  long double reference = 0;
  NICE_PRINT(acos, trig)
  FILL_TEST(acos(x), s21_acos(x))
}
END_TEST

Suite* acos_suite(void) {
  Suite* suite = suite_create("acos");
  TCase* acos_tcase = tcase_create("acos_case");

  tcase_add_loop_test(acos_tcase, acos_fract, 0, 10);
  tcase_add_loop_test(acos_tcase, acos_bad, 0, 6);
  tcase_add_loop_test(acos_tcase, acos_trig, 0, 6);

  tcase_set_tags(acos_tcase, "acos all");
  suite_add_tcase(suite, acos_tcase);
  return suite;
}
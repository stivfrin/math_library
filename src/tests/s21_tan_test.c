#include "math_tests.h"

START_TEST(tan_fract) {
  double samples_tan[] = SAMPLES_FRACT;
  double x = samples_tan[_i];
  long double reference = 0;
  NICE_PRINT(tan, fract)
  FILL_TEST(tan(x), s21_tan(x))
}
END_TEST

START_TEST(tan_bad) {
  double samples_tan[] = SAMPLES_BAD;
  double x = samples_tan[_i];
  long double reference = 0;
  NICE_PRINT(tan, bad)
  FILL_TEST(tan(x), s21_tan(x))
}
END_TEST

START_TEST(tan_trig) {
  double samples_tan[] = SAMPLES_TRIG;
  double x = samples_tan[_i];
  long double reference = 0;
  NICE_PRINT(tan, trig)
  FILL_TEST(tan(x), s21_tan(x))
}
END_TEST

Suite* tan_suite(void) {
  Suite* suite = suite_create("tan");
  TCase* tan_tcase = tcase_create("tan_case");

  tcase_add_loop_test(tan_tcase, tan_fract, 0, 10);
  tcase_add_loop_test(tan_tcase, tan_bad, 0, 6);
  tcase_add_loop_test(tan_tcase, tan_trig, 0, 6);

  tcase_set_tags(tan_tcase, "tan all");
  suite_add_tcase(suite, tan_tcase);
  return suite;
}
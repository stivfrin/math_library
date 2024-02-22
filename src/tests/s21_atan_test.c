#include "math_tests.h"

START_TEST(atan_fract) {
  double samples_atan[] = SAMPLES_FRACT;
  double x = samples_atan[_i];
  long double reference = 0;
  NICE_PRINT(atan, fract)
  FILL_TEST(atan(x), s21_atan(x))
}
END_TEST

START_TEST(atan_bad) {
  double samples_atan[] = SAMPLES_BAD;
  double x = samples_atan[_i];
  long double reference = 0;
  NICE_PRINT(atan, bad)
  FILL_TEST(atan(x), s21_atan(x))
}
END_TEST

START_TEST(atan_trig) {
  double samples_atan[] = SAMPLES_TRIG;
  double x = samples_atan[_i];
  long double reference = 0;
  NICE_PRINT(atan, trig)
  FILL_TEST(atan(x), s21_atan(x))
}
END_TEST

Suite* atan_suite(void) {
  Suite* suite = suite_create("atan");
  TCase* atan_tcase = tcase_create("atan_case");

  tcase_add_loop_test(atan_tcase, atan_fract, 0, 10);
  tcase_add_loop_test(atan_tcase, atan_bad, 0, 6);
  tcase_add_loop_test(atan_tcase, atan_trig, 0, 6);

  tcase_set_tags(atan_tcase, "atan all");
  suite_add_tcase(suite, atan_tcase);
  return suite;
}
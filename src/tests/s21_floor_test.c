#include "math_tests.h"

START_TEST(floor_fract) {
  double samples_floor[] = SAMPLES_FRACT;
  double x = samples_floor[_i];
  long double reference = 0;
  NICE_PRINT(floor, fract)
  FILL_TEST(floor(x), s21_floor(x))
}
END_TEST

START_TEST(floor_bad) {
  double samples_floor[] = SAMPLES_BAD;
  double x = samples_floor[_i];
  long double reference = 0;
  NICE_PRINT(floor, bad)
  FILL_TEST(floor(x), s21_floor(x))
}
END_TEST

Suite* floor_suite(void) {
  Suite* suite = suite_create("floor");
  TCase* floor_tcase = tcase_create("floor_case");

  tcase_add_loop_test(floor_tcase, floor_fract, 0, 10);
  tcase_add_loop_test(floor_tcase, floor_bad, 0, 6);

  tcase_set_tags(floor_tcase, "floor all");
  suite_add_tcase(suite, floor_tcase);
  return suite;
}
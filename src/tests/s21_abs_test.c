#include "math_tests.h"

START_TEST(abs_int) {
  int samples_abs[] = SAMPLES_INT;
  int x = samples_abs[_i];
  int reference = abs(x);
  ck_assert_int_eq(reference, s21_abs(x));
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12d] \033[0m %15s: %-15d"
      " our: %d\n",
      "abs_int", (_i + 1), x, "original", abs(x), s21_abs(x));
#endif
}
END_TEST

START_TEST(abs_bad) {
  double samples_abs[] = SAMPLES_BAD;
  int x = (int)samples_abs[_i];
  int reference = abs(x);
  reference = abs(x);
  ck_assert_int_eq(reference, s21_abs(x));
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12d] \033[0m %15s: %-15d"
      " our: %d\n",
      "abs_bad", (_i + 1), x, "original", abs(x), s21_abs(x));
#endif
}
END_TEST

Suite* abs_suite(void) {
  Suite* suite = suite_create("abs");
  TCase* abs_tcase = tcase_create("abs_case");

  tcase_add_loop_test(abs_tcase, abs_int, 0, 10);
  tcase_add_loop_test(abs_tcase, abs_bad, 0, 6);

  tcase_set_tags(abs_tcase, "abs all");
  suite_add_tcase(suite, abs_tcase);
  return suite;
}
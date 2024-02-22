#include "math_tests.h"

START_TEST(pow_fract) {
  double samples_pow[] = SAMPLES_FRACT;
  double x = samples_pow[_i], y = 0;
  long double reference = 0;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = 1.;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = -1.;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = 5;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = INFINITY;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = NAN;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
}
END_TEST

START_TEST(pow_bad) {
  double samples_pow[] = SAMPLES_BAD;
  double x = samples_pow[_i], y = 0;
  long double reference = 0;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_bad", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = 1.;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_bad", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = -1.;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_bad", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = 5;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_bad", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = INFINITY;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_bad", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
  y = NAN;
  FILL_TEST(pow(x, y), s21_pow(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "pow_fract", (_i + 1), x, y, "original", pow(x, y), s21_pow(x, y));
#endif
}
END_TEST

Suite* pow_suite(void) {
  Suite* suite = suite_create("pow");
  TCase* pow_tcase = tcase_create("pow_case");

  tcase_add_loop_test(pow_tcase, pow_fract, 0, 10);
  tcase_add_loop_test(pow_tcase, pow_bad, 0, 6);

  tcase_set_tags(pow_tcase, "pow all");
  suite_add_tcase(suite, pow_tcase);
  return suite;
}
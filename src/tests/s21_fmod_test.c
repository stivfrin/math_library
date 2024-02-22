#include "math_tests.h"

START_TEST(fmod_fract) {
  double samples_fmod[] = SAMPLES_FRACT;
  double x = samples_fmod[_i], y = 0;
  long double reference = 0;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = 1.;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = -1.;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = 5;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = INFINITY;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = NAN;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = x;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_fract", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
}
END_TEST

START_TEST(fmod_bad) {
  double samples_fmod[] = SAMPLES_BAD;
  double x = samples_fmod[_i], y = 0;
  long double reference = 0;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = 1.;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = -1.;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = 5;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = INFINITY;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
  y = NAN;
  FILL_TEST(fmod(x, y), s21_fmod(x, y))
#ifndef SILENT_MODE
  printf(
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf, %-12lf] \033[0m %15s: %-15lf"
      " our: %Lf\n",
      "fmod_bad", (_i + 1), x, y, "original", fmod(x, y), s21_fmod(x, y));
#endif
}
END_TEST

Suite* fmod_suite(void) {
  Suite* suite = suite_create("fmod");
  TCase* fmod_tcase = tcase_create("fmod_case");

  tcase_add_loop_test(fmod_tcase, fmod_fract, 0, 10);
  tcase_add_loop_test(fmod_tcase, fmod_bad, 0, 6);

  tcase_set_tags(fmod_tcase, "fmod all");
  suite_add_tcase(suite, fmod_tcase);
  return suite;
}
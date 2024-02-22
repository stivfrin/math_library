#include "s21_math.h"

long double s21_log(double x) {
  int exp_counter = 0;
  long double res = S21_NAN;
  long double compare = 0;
  if (IS_ZERO(x)) {
    res = -S21_INF;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else if (!IS_INF(x) && !IS_NAN(x) && x > 0) {
    res = 0;
    for (; x >= S21_E; x = x / S21_E, exp_counter++)
      ;
    for (int i = 0; i < 100; i++) {
      compare = res;
      res = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    res += exp_counter;
  }
  return res;
}
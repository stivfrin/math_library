#include "s21_math.h"

long double s21_exp(double x) {
  long double res = x;
  int reverse = 0;
  if (!IS_NAN(x) && !(x == S21_INF)) {
    if (x == -S21_INF)
      res = 0;
    else {
      if (x < 0) {
        reverse = 1;
        x = -x;
      }
      long double i = 0.;
      long double delta = 1.;
      long double sum = 1.;
      do {
        i++;
        delta *= x / i;
        sum += delta;
        if (sum > S21_FMAX) {
          sum = S21_INF;
          break;
        }
      } while (s21_fabs(delta) > S21_EPS);
      if (reverse) sum = 1. / sum;
      res = sum;
    }
  }
  return res;
}

#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 4, y = 0;

  while (s21_fabs(res - y) > S21_EPS) {
    if (x < 0) {
      res = S21_NAN;
      break;
    } else if (x == S21_INF) {
      res = x;
      break;
    }
    y = res;
    res = (y + x / y) / 2;
  }
  return res;
}
#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0.;
  if (s21_fabs(x) > (S21_PI / 2 - S21_EPS) &&
      s21_fabs(x) < (S21_PI / 2 + S21_EPS)) {
    res = (x > 0) ? S21_TAN_MAX : -S21_TAN_MAX;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

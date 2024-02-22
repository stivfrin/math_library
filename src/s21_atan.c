#include "s21_math.h"

long double s21_atan(double x) {
  long double sum = 0.;

  long double delta = 0.;
  int i = 0;
  if IS_NAN (x) {
    sum = x;
  } else if IS_INF (x) {
    if (x > 0)
      sum = (S21_PI / 2.);
    else
      sum = -(S21_PI / 2.);
  } else if (s21_fabs(x) > (1. - S21_EPS) && s21_fabs(x) < (1. + S21_EPS)) {
    sum = x * S21_PI / 4.;
  } else {
    int sign = 1;
    if (s21_fabs(x) > 1.) sign = -1;
    do {
      delta = s21_ipow(x, sign * (1 + 2 * i)) / (1 + 2 * i);
      if (i % 2)
        sum -= delta;
      else
        sum += delta;
      i++;
    } while (s21_fabs(delta) > S21_EPS);
    if (sign == -1) sum = ((S21_PI * s21_fabs(x)) / (2 * x)) - sum;
  }
  return sum;
}
#include "s21_math.h"

long double s21_fabs(double x) {
  long double res = 0.;

  if (x != 0. && x != -0.) res = (x > S21_EPS) ? x : -x;
  return res;
}

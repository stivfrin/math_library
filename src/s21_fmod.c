#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = S21_NAN;

  if (IS_NAN(x) || IS_INF(y)) {
    if (!IS_INF(x)) res = x;
  } else {
    if (!IS_INF(x) && !IS_ZERO(y)) {
      res = x - ((int)(x / y)) * y;
    }
    if IS_NAN (y) res = y;
  }
  return res;
}

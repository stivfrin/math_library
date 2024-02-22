#include "s21_math.h"

long double s21_ceil(double x) {
  double res = 0.0;

  long int y;
  if (IS_NAN(x) || IS_INF(x)) {
    res = x;
  } else if (x < 0) {
    y = x;
    res = y;
  } else if (x > 0) {
    if (x != (int)x) {
      x += 1;
      long int y = x;
      res = y;
    } else {
      res = x;
    }
  }
  return res;
}

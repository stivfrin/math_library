#include "s21_math.h"

long double s21_floor(double x) {
  double res;

  if (x < 0) {
    if (x != (int)x) x = x - 1;
    long int y = x;
    res = y;
  } else if (x >= 0) {
    long int y = x;
    res = y;
  }
  if (IS_NAN(x) || IS_INF(x)) {
    res = x;
  }
  return res;
}

#include "s21_math.h"

int s21_abs(int x) {
  int res = 0;

  res = (x > 0) ? x : -x;
  return res;
}

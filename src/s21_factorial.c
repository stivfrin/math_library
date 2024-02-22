#include "s21_math.h"

long double s21_factorial(int x) {
  long double res = 1;

  if (x < 0)
    res = 0;
  else {
    for (int k = x; k > 0; k--) res *= k;
  }
  return res;
}

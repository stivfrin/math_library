#include "s21_math.h"

long double s21_ipow(long double base, int exp) {
  long double res = 1.;

  for (int k = 0; k < exp; k++) {
    res *= base;
  }
  for (int k = 0; k > exp; k--) {
    res /= base;
  }
  return res;
}
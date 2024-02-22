#include "s21_math.h"

long double s21_sin(double x) {
  if (s21_fabs(x) > 2 * S21_PI) x = s21_fmod(x, 2 * S21_PI);
  if (x > S21_PI) x -= 2 * S21_PI;
  if (x < S21_PI) x += 2 * S21_PI;

  long double sum = 0.;
  long double delta = 0.;
  int i = 0;
  do {
    delta = s21_ipow(x, 2 * i + 1) / s21_factorial(2 * i + 1);
    if (i % 2)
      sum -= delta;
    else
      sum += delta;
    i++;
  } while (s21_fabs(delta) > S21_EPS);
  return sum;
}

#ifndef MATH_H
#define MATH_H

#define S21_EPS 1E-8
#define S21_FMAX 1.7976931348623157E+308
#define S21_PI 3.1415926535897932384626433832795
#define S21_E 2.71828182845904523536028747
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_TAN_MAX 16331239353195370

#define IS_INF(X) (X == (S21_INF) || X == (-S21_INF))
#define IS_NAN(X) (!(X == X))
#define IS_ZERO(X) (s21_fabs(X) < S21_EPS)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_ipow(long double base, int exp);
long double s21_factorial(int x);

#endif
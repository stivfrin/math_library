#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

#define SAMPLES_INT \
  { 0, 1, 10, INT_MIN, -777, -2, 101, INT_MAX, 1337, -9 }  // 10
#define SAMPLES_FRACT \
  { 0, 0.5, 1, 9.9999, LDBL_MAX, S21_E, -100, 0.25, -0.1, LDBL_MIN }  // 10
#define SAMPLES_BAD \
  { 0., -INFINITY, -NAN, NAN, -0., INFINITY }  // 6
#define SAMPLES_TRIG \
  { 0., -0., S21_PI, S21_PI / 2., -S21_PI / 2., S21_PI / 4. }  // 6

Suite* abs_suite(void);
Suite* acos_suite(void);
Suite* asin_suite(void);
Suite* atan_suite(void);
Suite* ceil_suite(void);
Suite* cos_suite(void);
Suite* exp_suite(void);
Suite* fabs_suite(void);
Suite* floor_suite(void);
Suite* fmod_suite(void);
Suite* log_suite(void);
Suite* pow_suite(void);
Suite* sin_suite(void);
Suite* sqrt_suite(void);
Suite* tan_suite(void);

#define FILL_TEST(ref, our)                            \
  reference = ref;                                     \
  if IS_NAN (reference) {                              \
    ck_assert_ldouble_nan(our);                        \
  } else if IS_INF (reference) {                       \
    ck_assert(our == reference);                       \
  } else {                                             \
    ck_assert_ldouble_eq_tol(reference, our, S21_EPS); \
  }

//#define SILENT_MODE // заглушка
#ifndef SILENT_MODE
#define NICE_PRINT(f, s_type)                                      \
  printf(                                                          \
      "\033[0;32m%-25s %-3d \x1b[33m[%-12lf] \033[0m %15s: %-15lf" \
      " our: %Lf\n",                                               \
      #f "_" #s_type, (_i), x, "original", f(x), s21_##f(x));
#else
#define NICE_PRINT(a, b) ;
#endif

#ifndef VM
#define VM 1
#endif

#define STR_VALUE(arg) #arg
#define PARSE(name) STR_VALUE(name)
#define TEST_TAGS PARSE(TT)

#define VERB_MODE VM

#endif
#include "include/header.h"
#include <omp.h>

int sum(const int *arr, int size) {
  long long sum = 0;
#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < size; ++i) {
    sum += arr[i] * i;
  }
  return sum;
}

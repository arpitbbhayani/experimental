#include "include/header.h"

int sum(const int *arr, int size) {
  int sum = 0;
  int i = 0;
  for (; i < size - 3; i += 4) {
    sum += arr[i] * i + arr[i + 1] * (i + 1) + arr[i + 2] * (i + 2) +
           arr[i + 3] * (i + 3);
  }
  for (; i < size; ++i) {
    sum += arr[i] * i;
  }
  return sum;
}

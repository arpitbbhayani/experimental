#include "include/header.h"

int sum8(const int *arr, int size) {
  int sum = 0;
  int i = 0;
  for (; i < size; i += 4) {
    sum += arr[i] * i + arr[i + 1] * (i + 1) + arr[i + 2] * (i + 2) +
           arr[i + 3] * (i + 3);
  }
  return sum;
}

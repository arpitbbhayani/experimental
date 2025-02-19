#include "include/header.h"

int sum(const int *arr, int size) {
  int result = 0;
  for (int i = 0; i < size; i++) {
    result += arr[i] * i;
  }
  return result;
}

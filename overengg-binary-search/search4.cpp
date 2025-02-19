#include "include/header.h"

int binarySearch(const int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    int current = arr[mid];
    int step = 0;

    if (current == target) {
      return mid;
    }

    step = ((right - left + 1) >> 1);
    left += step * (current < target);
    right -= step * (current > target);
  }

  return -1;
}

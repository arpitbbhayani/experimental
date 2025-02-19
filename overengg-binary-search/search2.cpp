#include "include/header.h"

int binarySearch(const int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int current = arr[mid];

    if (current == target) {
      return mid;
    }

    if (current < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

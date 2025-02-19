#include "include/header.h"

int _binarySearch(const int arr[], int target, int left, int right) {
  if (left > right) {
    return -1;
  }

  int mid = (left + right) / 2;
  int current = arr[mid];

  if (current == target) {
    return mid;
  }

  if (current > target) {
    return _binarySearch(arr, target, left, mid - 1);
  }
  return _binarySearch(arr, target, mid + 1, right);
}

int binarySearch(const int arr[], int size, int target) {
  return _binarySearch(arr, target, 0, size - 1);
}

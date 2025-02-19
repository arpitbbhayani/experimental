#include "include/header.h"

int _binarySearch(const int arr[], int target, int left, int right) {
  if (left > right) {
    return -1;
  }

  int mid = (left + right) / 2;
  if (arr[mid] == target) {
    return mid;
  }

  if (arr[mid] > target) {
    return _binarySearch(arr, target, left, mid - 1);
  }
  return _binarySearch(arr, target, mid + 1, right);
}

int binarySearch(const int arr[], int size, int target) {
  return _binarySearch(arr, target, 0, size - 1);
}

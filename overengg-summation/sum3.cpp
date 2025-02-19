#include "include/header.h"
#include <immintrin.h>

int sum(const int *arr, int size) {
  long long sum = 0;
  int i = 0;

  for (; i < size - 7; i += 8) { // Process 8 elements at a time
    __m256i v_arr = _mm256_loadu_si256((const __m256i *)&arr[i]); // Load 8 ints

    // Create a vector of indices (this part is tricky and can be further
    // optimized)
    __m256i v_indices =
        _mm256_set_epi32(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);

    __m256i v_products =
        _mm256_mul_epi32(v_arr, v_indices); // Multiply element-wise
    sum += _mm256_extract_epi64(v_products, 0) +
           _mm256_extract_epi64(v_products, 1) +
           _mm256_extract_epi64(v_products, 2) +
           _mm256_extract_epi64(v_products, 3);
  }
  for (; i < size; ++i) {
    sum += arr[i] * i;
  }

  return sum;
}

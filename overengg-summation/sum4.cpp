#include "include/header.h"
#include <immintrin.h>

// vectorized sum calculation using Intel's AVX2 (Advanced Vector Extensions 2)
// instructions.
int sum8(const int *arr, int size) {
  int sum = 0;
  int i = 0;

  for (; i < size; i += 8) { // Process 8 elements at a time
    // __m256i is a 256-bit vector that can hold 8 32-bit integers
    // loads 8 consecutive integers from memory into the vector
    __m256i v_arr = _mm256_loadu_si256((const __m256i *)&arr[i]);

    // Creates a vector containing the indices (i, i+1, i+2, etc.)
    // We have to reverse the order of the indices to match the order of the
    // elements in the array. Given how the AVX2 instructions work
    // (loadu_si256), the first element of the vector will be the last element
    // of the array.
    __m256i v_indices =
        _mm256_set_epi32(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);

    // Multiplies each array element by its index in parallel
    __m256i v_products = _mm256_mullo_epi32(v_arr, v_indices);

    // Extract integer byte or word from packed integer array
    // element selected by index.
    sum += _mm256_extract_epi32(v_products, 0) +
           _mm256_extract_epi32(v_products, 1) +
           _mm256_extract_epi32(v_products, 2) +
           _mm256_extract_epi32(v_products, 3) +
           _mm256_extract_epi32(v_products, 4) +
           _mm256_extract_epi32(v_products, 5) +
           _mm256_extract_epi32(v_products, 6) +
           _mm256_extract_epi32(v_products, 7);
  }
  return sum;
}

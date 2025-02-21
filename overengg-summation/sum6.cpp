#include "include/header.h"
#include <immintrin.h>

// vectorized sum calculation using Intel's AVX2 (Advanced Vector Extensions 2)
// instructions.
int sum8(const int *arr, int size) {
  int sum = 0;
  int i = 0;

  __m256i total_sum = _mm256_setzero_si256();
  __m256i base_indices = _mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0);

  for (; i < size; i += 8) { // Process 8 elements at a time
    // __m256i is a 256-bit vector that can hold 8 32-bit integers
    // loads 8 consecutive integers from memory into the vector
    __m256i v_arr = _mm256_loadu_si256((const __m256i *)&arr[i]);

    // Adds the base indices to the current index to get the indices of the
    // elements in the array.
    __m256i v_indices = _mm256_add_epi32(base_indices, _mm256_set1_epi32(i));

    // Multiplies each array element by its index in parallel
    __m256i v_products = _mm256_mullo_epi32(v_arr, v_indices);

    total_sum = _mm256_add_epi32(total_sum, v_products);
  }

  // Extract lower and upper 128-bit lanes
  __m128i sum128 = _mm_add_epi32(_mm256_extracti128_si256(total_sum, 0),
                                 _mm256_extracti128_si256(total_sum, 1));

  // Reduce final 4 elements in the 128-bit register
  return _mm_extract_epi32(sum128, 0) + _mm_extract_epi32(sum128, 1) +
         _mm_extract_epi32(sum128, 2) + _mm_extract_epi32(sum128, 3);
}

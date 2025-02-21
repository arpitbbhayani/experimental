#include <immintrin.h>
#include <stdio.h>

int main() {
  __m256i v_vals = _mm256_set_epi32(8, 4, 1, 2, 3, 9, 2, 7);

  printf("%d\n", _mm256_extract_epi32(v_vals, 0));
  printf("%d\n", _mm256_extract_epi32(v_vals, 1));
  printf("%d\n", _mm256_extract_epi32(v_vals, 2));
  printf("%d\n", _mm256_extract_epi32(v_vals, 3));
  printf("%d\n", _mm256_extract_epi32(v_vals, 4));
  printf("%d\n", _mm256_extract_epi32(v_vals, 5));
  printf("%d\n", _mm256_extract_epi32(v_vals, 6));
  printf("%d\n", _mm256_extract_epi32(v_vals, 7));

  return 0;
}

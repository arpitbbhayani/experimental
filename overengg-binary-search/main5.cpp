#include <immintrin.h>
#include <cstdint>

int binarySearch(const int32_t* arr, int size, int32_t target) {
    if (size == 0) return -1;
    
    // Create vector with target value replicated 8 times
    __m256i target_vec = _mm256_set1_epi32(target);
    
    int left = 0;
    int right = size - 1;
    
    // Handle groups of 8 elements at a time
    while (right - left >= 8) {
        int mid = left + ((right - left) / 16) * 8; // Ensure mid is aligned to 8 elements
        
        // Load 8 consecutive integers
        __m256i current = _mm256_loadu_si256((__m256i*)(arr + mid));
        
        // Compare all 8 elements with target
        __m256i cmp_eq = _mm256_cmpeq_epi32(current, target_vec);
        __m256i cmp_lt = _mm256_cmpgt_epi32(target_vec, current);
        
        // Get masks from comparisons
        int eq_mask = _mm256_movemask_ps(_mm256_castsi256_ps(cmp_eq));
        int lt_mask = _mm256_movemask_ps(_mm256_castsi256_ps(cmp_lt));
        
        // Check if target was found
        if (eq_mask != 0) {
            // Find the first occurrence using trailing zeros
            return mid + __builtin_ctz(eq_mask);
        }
        
        // Count number of elements less than target
        int lt_count = _mm_popcnt_u32(lt_mask);
        
        if (lt_count == 8) {
            // All elements are less than target, search right half
            left = mid + 8;
        } else {
            // Some elements are greater, search left half
            right = mid + lt_count - 1;
        }
    }
    
    // Fall back to scalar binary search for remaining elements
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

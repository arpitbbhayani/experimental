#include "include/header.h"
#include <benchmark/benchmark.h>

static void BM_Sum(benchmark::State &state) {
  int size = state.range(0);
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(sum8(arr, size));
  }

  delete[] arr;
}

BENCHMARK(BM_Sum)->RangeMultiplier(8)->Range(8, 8 << 20);
BENCHMARK_MAIN();

// int main(int argc, char **argv) {
//   int size = 8;
//   int *arr = new int[size];
//   for (int i = 0; i < size; i++) {
//     arr[i] = i;
//   }
//   std::cout << sum8(arr, size) << std::endl;
//   return 0;
// }

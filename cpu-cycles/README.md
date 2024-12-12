# CPU Cycles

The program runs the fibonacci function 3 times and measures the CPU cycles.

```
$ make run
```

## Reading the CPU profile output

1. Flat Time (0.68s, 0.35s, etc.)

   - Represents the time spent directly in that specific function
   - Does NOT include time spent in functions called by this function
   - Purely the time the CPU spent executing the instructions in this exact function

2. Flat% (65.38%, 33.65%, etc.)

   - Percentage of total CPU time spent directly in this function
   - Shows the proportion of total profiling time for this specific function

3. Sum%

   - Cumulative percentage of total time up to and including this function
   - Helps you understand the running total of CPU time across functions

4. Cum (Cumulative) Time (0.68s, 0.35s, etc.)

   - Total time spent in this function AND all functions it calls
   - Includes both the function's own execution time and time spent in its sub-functions
   - Gives a more comprehensive view of a function's total computational cost

5. Cum%

   - Percentage of total CPU time for this function including all its sub-function calls
   - Shows the total impact of the function on overall program performance

These times are CPU samples, representing the profiler's snapshots of where the CPU was
spending time during the program's execution. They are not wall clock time, but CPU utilization time.

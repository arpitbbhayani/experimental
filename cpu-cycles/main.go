package main

import (
	"fmt"
	"net/http"
	"os"
	"runtime/pprof"
)

// fib1 calculates the nth Fibonacci number using a recursive approach.
// This function is intentionally inefficient for demonstration purposes.
func fib1(n int) int {
	if n <= 1 {
		return n
	}
	return fib1(n-1) + fib1(n-2)
}

// fib2 is another implementation of the Fibonacci calculation, identical to fib1.
// It is used to demonstrate profiling of multiple similar functions.
func fib2(n int) int {
	if n <= 1 {
		return n
	}
	return fib2(n-1) + fib2(n-2)
}

// httpCall makes an HTTP GET request to a specified URL.
// The purpose is to demonstrate that network calls should not consume CPU cycles
// significantly, but any CPU cycles consumed during the call should be visible in the profile.
func httpCall() {
	// fib1(40)  // Uncomment to induce a call to the fib function to consume some cycles

	// Perform a network call to Google's homepage
	r, err := http.Get("https://www.google.com")
	if err != nil {
		fmt.Println("could not make http call: %w", err)
		return
	}
	fmt.Println(r.StatusCode)
}

func main() {
	// Create a file to store the CPU profile data
	cf, err := os.Create("cpu.prof")
	if err != nil {
		fmt.Println("could not create cpu.prof: %w", err)
		return
	}
	defer cf.Close()

	// Start CPU profiling and write the data to the created file
	if err = pprof.StartCPUProfile(cf); err != nil {
		fmt.Println("could not start CPU profile: %w", err)
		return
	}
	defer pprof.StopCPUProfile()

	fmt.Println(fib1(40))
	// fmt.Println(fib2(40))
	// httpCall()
}

package main

import (
	"fmt"
	"os"
	"runtime/pprof"
)

func fib(n int) int {
	if n <= 1 {
		return n
	}
	return fib(n-1) + fib(n-2)
}

func main() {
	cf, err := os.Create("cpu.prof")
	if err != nil {
		fmt.Println("could not create cpu.prof: %w", err)
		return
	}
	defer cf.Close()

	if err = pprof.StartCPUProfile(cf); err != nil {
		fmt.Println("could not start CPU profile: %w", err)
		return
	}
	defer pprof.StopCPUProfile()

	for i := 0; i < 3; i++ {
		fmt.Println(fib(40))
	}
}

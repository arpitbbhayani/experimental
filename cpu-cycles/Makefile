run:
	${MAKE} clean
	go build -gcflags "all=-N -l" main.go
	./main
	go tool pprof -http=localhost:8080 cpu.prof

clean:
	rm -f main cpu.prof

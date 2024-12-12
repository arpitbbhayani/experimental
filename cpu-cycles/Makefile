run:
	${MAKE} clean
	go build -gcflags "all=-N -l" main.go
	./main
	go tool pprof --text cpu.prof

clean:
	rm -f main cpu.prof

run: sum1

sum1:
	g++ -O0 main.cpp sum1.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

clean:
	rm main

SRC_FILES := $(wildcard *.cpp include/*.h)

format:
	clang-format -i $(SRC_FILES)

lint:
	clang-tidy $(SRC_FILES) -- -Iinclude

lint-format: format lint

.PHONY: format lint lint-format

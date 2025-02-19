run: sum1 sum2 sum3 sum4 sum5

sum1:
	g++ -O0 main.cpp sum1.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

sum2:
	g++ -O0 main.cpp sum2.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

sum3:
	g++ -O0 main.cpp sum3.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

sum4:
	g++ -O0 -mavx2 main.cpp sum4.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

sum5:
	g++ -O0 -fopenmp main.cpp sum5.cpp -o main -lbenchmark -lpthread -Iinclude
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

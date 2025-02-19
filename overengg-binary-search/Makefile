run: run1 run2 run3 run4

run1:
	g++ -O0 utils.cpp main1.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

run2:
	g++ -O0 utils.cpp main2.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

run3:
	g++ -O0 utils.cpp main3.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

run4:
	g++ -O0 utils.cpp main4.cpp -o main -lbenchmark -lpthread -Iinclude
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

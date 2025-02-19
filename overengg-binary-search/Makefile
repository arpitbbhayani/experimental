run: search1 search2 search3 search4 search5

search1:
	g++ -O0 main.cpp search1.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

search2:
	g++ -O0 main.cpp search2.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

search3:
	g++ -O0 main.cpp search3.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

search4:
	g++ -O0 main.cpp search4.cpp -o main -lbenchmark -lpthread -Iinclude
	./main

search5:
	g++ -O0 -mavx2 main.cpp search5.cpp -o main -lbenchmark -lpthread -Iinclude
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

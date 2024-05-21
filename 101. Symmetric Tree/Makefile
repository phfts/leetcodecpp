.PHONY: debug test

test:
	mkdir -p bin/
	g++ tests/main.cpp -std=c++23 -lgtest -o bin/test
	./bin/test

debug:
	mkdir -p bin/
	g++ tests/main.cpp -std=c++23 -g -lgtest -o bin/test
	gdb ./bin/test
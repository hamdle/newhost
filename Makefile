.PHONY: all build clean rebuild run

all: build

build:
	@echo "Building..."
	g++ -o build/newhost newhost.cpp

clean:
	@echo "Cleaning build..."
	rm -rf build/
	mkdir build

rebuild: clean build

run:
	./build/newhost
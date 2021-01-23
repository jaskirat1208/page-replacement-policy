all:
	mkdir -p bin
	make _compile 

_compile:
	g++ src/main.cpp -o bin/main

clean:
	rm -rf bin
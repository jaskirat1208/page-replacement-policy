all:
	mkdir -p bin
	make _compile 
	make _docs

_compile:
	g++ -std=c++14 src/main.cpp -o bin/main

_docs:
	doxygen page-replacement-policy

clean:
	rm -rf bin
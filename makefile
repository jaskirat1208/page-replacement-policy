all:
	mkdir -p bin
	make _compile 
	make _docs

_compile:
	g++ src/main.cpp -o bin/main

_docs:
	doxygen page-replacement-policy

clean:
	rm -rf bin
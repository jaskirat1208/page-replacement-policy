compile: 
	g++ main.cpp fs.cpp page.cpp memory.cpp  -o main

all:
	make compile
	./a.out


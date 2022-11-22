all: shell

shell: shell.cpp
	g++ -g -O3 -o shell shell.cpp --std=c++11

clean:
	rm -f shell
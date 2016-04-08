CFLAGS=-std=c++11
CPP=g++

all: main.cpp rbtree.cpp
	$(CPP) -o rbtree main.cpp rbtree.cpp $(CFLAGS)
clean:
	rm rbtree

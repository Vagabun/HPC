.PHONY: all clean test
all: a.out
clean:
	rm *.out *.so *.o
test: b.out
libavl-tree.so: avl_tree.o
	gcc -shared -o libavl-tree.so avl_tree.o
avl_tree.o: avl_tree.c
	gcc -fpic -c avl_tree.c
main.o:
	gcc -c main.c
a.out: libavl-tree.so avl_tree.o
	gcc -L . -lavl-tree main.c
b.out: avl_tree.o main.o
	gcc avl_tree.o main.o -o b.out

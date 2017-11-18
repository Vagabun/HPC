.PHONY: all clean
all: a.out
clean:
	rm *.out *.so *.o
libavl-tree.so: avl_tree.o
	gcc -shared -o libavl-tree.so avl_tree.o
avl_tree.o: avl_tree.c
	gcc -fpic -c avl_tree.c
a.out: libavl-tree.so avl_tree.o
	gcc -L . -lavl-tree main.c

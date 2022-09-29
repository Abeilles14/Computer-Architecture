all: assignment1
assignment1: assignment1.o sortnew.o sortoriginal.o
	gcc -O3 assignment1.o sortnew.o sortoriginal.o -o assignment1.bin
sortnew.o: sortnew.c
	gcc -c sortnew.c
sortoriginal.o: sortoriginal.c
	gcc -c sortoriginal.c
clean:
	rm sortnew.o sortoriginal.o sortoriginal.inst sortnew.inst assignment1.bin

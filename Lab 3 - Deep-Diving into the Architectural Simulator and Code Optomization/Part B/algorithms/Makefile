all: assignment3
assignment3: assignment3.o matmul_opt1.o matmul_opt2.o matmul_basic.o
	gcc -O3 assignment3.o matmul_opt1.o matmul_opt2.o matmul_basic.o -o assignment3.bin
matmul_basic.o: matmul_basic.c
	gcc -c matmul_basic.c
matmul_opt1.o: matmul_opt1.c
	gcc -c matmul_opt1.c
matmul_opt2.o: matmul_opt2.c
	gcc -c matmul_opt2.c
clean:
	rm matmul_opt1.o matmul_opt2.o matmul_basic.o assignment3.bin

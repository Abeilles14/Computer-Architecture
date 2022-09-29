#!/bin/bash
./assignment1.bin 0 $1
./assignment1.bin 1 $1
objdump -dS -M intel sortoriginal.o > sortoriginal.inst
objdump -dS -M intel sortnew.o > sortnew.inst

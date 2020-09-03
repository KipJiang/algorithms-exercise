CC=g++
CCFLAG=-std=c++11 -Wall -I.

SOURCES=top_ten_sort_algo.cpp
OBJS=top_ten_sort_algo.o
OUTPUT=top_10_sort

main:
	$(CC) -o $(OUTPUT) $(CCFLAG) $(SOURCES)

clean:
	rm -f $(OBJS) $(OUTPUT) a.out

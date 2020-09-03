CC=g++
CCFLAG=-std=c++11 -Wall -I.

SOURCES=top10Sort.cpp
OBJS=top10Sort.o
OUTPUT=top10Sort

main:
	$(CC) -o $(OUTPUT) $(CCFLAG) $(SOURCES)

clean:
	rm -f $(OBJS) $(OUTPUT) a.out

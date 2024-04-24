CC = gcc
CFLAGS = -Wall -Wextra -std=c99

myprogram: main.o
	$(CC) $(CFLAGS) -o myprogram main.o

main.o: main.c grades.h marks.h marks_card.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o myprogram

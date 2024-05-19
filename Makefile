CC = gcc
CFLAGS = -Wall

all: details.exe marks.exe markscard.exe main.exe

details.exe: details.o
	$(CC) $(CFLAGS) -o details.exe details.o

marks.exe: marks.o
	$(CC) $(CFLAGS) -o marks.exe marks.o

markscard.exe: markscard.o
	$(CC) $(CFLAGS) -o markscard.exe markscard.o

main.exe: main.o
	$(CC) $(CFLAGS) -o main.exe main.o

details.o: details.c
	$(CC) $(CFLAGS) -c details.c

marks.o: marks.c
	$(CC) $(CFLAGS) -c marks.c

markscard.o: markscard.c
	$(CC) $(CFLAGS) -c markscard.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o details.exe marks.exe markscard.exe main.exe

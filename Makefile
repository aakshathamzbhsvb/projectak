CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c
OBJS = main.o
HEADERS = marks.h grades.h marks_card.h

TARGET = myprogram

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)

#usar make / make clean
CC = gcc
CFLAGS = -Wall -g
OBJETS = main.o machine.o wordle.o maxHeap.o
TARGET = ourWordle

$(TARGET): $(OBJETS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJETS)

wordl.o: main.c
	$(CC) $(CFLAGS) -c main.c

machine.o: machine.c
	$(CC) $(CFLAGS) -c machine.c

ed1.o: wordle.c
	$(CC) $(CFLAGS) -c wordle.c

ed2.o: maxHeap.c
	$(CC) $(CFLAGS) -c maxHeap.c

clean:
	rm -f $(OBJETS) $(TARGET)

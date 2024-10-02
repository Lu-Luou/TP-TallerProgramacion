#usar make / make clean
CC = gcc
CFLAGS = -Wall -g
OBJETS = wordl.o machine.o ed1.o ed2.o
TARGET = ourWordle

$(TARGET): $(OBJETS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJETS)

wordl.o: wordl.c
	$(CC) $(CFLAGS) -c wordl.c

machine.o: machine.c
	$(CC) $(CFLAGS) -c machine.c

ed1.o: ed1.c
	$(CC) $(CFLAGS) -c ed1.c

ed2.o: ed2.c
	$(CC) $(CFLAGS) -c ed2.c

clean:
	rm -f $(OBJETS) $(TARGET)

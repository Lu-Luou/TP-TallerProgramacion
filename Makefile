#usar make / make clean
CC = gcc
CFLAGS = -Wall -g
OBJETS = wordl.o machine.o ed1.o ed2.o
TARGET = ourWordle

$(TARGET): $(OBJETS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJETS)

archivo1.o: wordl.c
	$(CC) $(CFLAGS) -c wordl.c

archivo2.o: machine.c
	$(CC) $(CFLAGS) -c machine.c

archivo3.o: ed1.c
	$(CC) $(CFLAGS) -c ed1.c

archivo4.o: ed2.c
	$(CC) $(CFLAGS) -c ed2.c

clean:
	rm -f $(OBJETS) $(TARGET)

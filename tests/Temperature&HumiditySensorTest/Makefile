OBJS = dht22.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LIBS = -I/usr/local/include -L/usr/local/lib -lwiringPi

all: $(OBJS)
	$(CC) $(LIBS) $(LFLAGS) $(OBJS) -o a.out

dht22.o: dht22.c
	$(CC) $(CFLAGS) dht22.c

clean:
	\rm *.o *~ a.out

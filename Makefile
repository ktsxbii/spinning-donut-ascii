CC = gcc
CFLAGS = -Wall -O3
LIBS = -lm

donut: donut.c
	$(CC) $(CFLAGS) donut.c -o donut $(LIBS)

clean:
	rm -f donut

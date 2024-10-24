# copilot: generate makefile to compile flow.c to flow

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

flow: flow.c
	$(CC) $(CFLAGS) -o flow flow.c $(LDFLAGS)

clean:
	rm -f flow

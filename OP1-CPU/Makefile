CC = g++
LIBS = 
INCLUDES = -I.
LDFLAGS = 

OBJECTS = benchmarks.o \
          
CFLAGS = -Wall -O0 -std=gnu++11

all: main
 
main: main.o $(OBJECTS)
	$(CC) -o $(CFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS): Makefile

.c.o: 
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< 

clean:
	rm *.o main

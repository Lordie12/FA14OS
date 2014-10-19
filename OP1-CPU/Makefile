CC = g++
LIBS = -L/usr/lib
INCLUDES = -I/usr/include
LDFLAGS = 

OBJECTS = benchmarks.o
          
CFLAGS = -Wall -O0 -std=c++11 -Wno-c++11-extensions
CXXFLAGS = -Wall -O0 -std=c++11 -Wno-c++11-extensions

all: main
 
main: main.o $(OBJECTS)
	$(CC) -o $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS): Makefile

.c.o: 
	$(CC) -c $(CXXFLAGS) $(INCLUDES) -o $@ $< 

clean:
	rm *.o main

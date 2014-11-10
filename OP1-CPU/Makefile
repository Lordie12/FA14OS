CXX = g++
LIBS = -L/usr/lib
INCLUDES = -I/usr/include
LDFLAGS = 

OBJECTS = benchmarks.o
          
CXXFLAGS = -Wall -O0 -std=c++11 -Wno-c++11-extensions

all: main
 
main: main.o $(OBJECTS)
	$(CXX) -o $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(OBJECTS): Makefile

.c.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $< 

clean:
	rm *.o main

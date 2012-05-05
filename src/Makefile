# This is literally my first makefile. It's bad.

# G++ Macports 4.7
CC=g++-mp-4.7
CFLAGS=-std=c++11 -Wall

# -l
LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf

#-I
INCLUDES=-I /usr/local/include/SDL2

SOURCES=$(wildcard *.cpp)
# changes every .cpp to .o
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))
MAIN=Sdl2Cpp11Test

all: $(MAIN)

$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJECTS) $(LIBS)

# does all the object files apparently?
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm *.o $(MAIN)

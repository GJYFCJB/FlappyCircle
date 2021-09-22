SRCDIR = .
INCLUDE = -I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)
# Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window

CC=g++

.PHONY : all
all : game

# List of all object files to link together.
OBJS = main.o Bird.o Wall.o Walls.o

main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $<

Bird.o: $(SRCDIR)/Bird.cpp
	$(CC) $(CFLAGS) -c $<

Wall.o: $(SRCDIR)/Wall.cpp
	$(CC) $(CFLAGS) -c $<

Walls.o: $(SRCDIR)/Walls.cpp
	$(CC) $(CFLAGS) -c $<

game: $(OBJS)
	$(CC) $(LFLAGS) -o flappyCircle $(OBJS)


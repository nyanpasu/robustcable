# I have no idea why this project even needs a makefile.
# But I'm writing one for the heck of it and to save myself
# a few keystrokes compiling.

CC = g++
CFLAGS = -std=c++11 -lSDL2 -lSDL2_image

all:
	$(CC) -o robustcable main.cpp $(CFLAGS)

clean:
	rm robustcable

CFLAGS = -Wall
C = g++
COMPILE = $(CC) $(CFLAGS)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all :
	g++ -c *.c++ -lsfml-graphics -lsfml-window -lsfml-system && g++ *.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o planetB

clean :
	rm *.o planetB

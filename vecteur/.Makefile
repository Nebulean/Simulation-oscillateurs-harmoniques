CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++11 -W -Wall

all: testvecteur

testvecteur: testvecteur.o vecteur.o

testvecteur.o: testvecteur.cc vecteur.h

vecteur.o: vecteur.cc vecteur.h

clean:
	rm *.o testvecteur

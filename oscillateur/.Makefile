CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++11 -W -Wall

all: testoscillateur

testoscillateur: testoscillateur.o oscillateur.o ../vecteur/vecteur.o

vecteur.o: ../vecteur/vecteur.cc ../vecteur/vecteur.h

oscillateur.o: oscillateur.cc oscillateur.h

testoscillateur.o: testoscillateur.cc oscillateur.h ../vecteur/vecteur.h

clean:
	rm *.o testoscillateur

CXX = g++
CC = $(CXX)

CXXFLAGS = -std=c++11 -W -Wall

all: testintegrateur

testintegrateur: testintegrateur.o # ../oscillateur/oscillateur.o # ../oscillateur.o ../vecteur/vecteur.o

integrateur.o: integrateur.cc integrateur.h ../oscillateur/oscillateur.h

testintegrateur.o: testintegrateur.cc integrateur.h

oscillateur.o:
	make ../oscillateur/Makefile

clean:
	rm *.o testintegrateur

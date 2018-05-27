# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testvecteur.cc vecteur.cc

HEADERS = vecteur.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
OBJECTS_DIR = ../../../build/

# le nom de l'executable.
TARGET = testvecteur

# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testoscillateur.cc oscillateur.cc ../vecteur/vecteur.cc

HEADERS = oscillateur.h ../vecteur/vecteur.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testoscillateur

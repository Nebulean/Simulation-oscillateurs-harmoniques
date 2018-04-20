# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testressort.cc ressort.cc ../oscillateur/oscillateur.cc ../eulercromer/eulercromer.cc ../vecteur/vecteur.cc

HEADERS = ressort.h ../oscillateur/oscillateur.h ../eulercromer/eulercromer.h ../vecteur/vecteur.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testressort

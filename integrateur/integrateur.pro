# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testintegrateur.cc integrateur.cc ../oscillateur/oscillateur.cc ../vecteur/vecteur.cc

HEADERS = integrateur.h ../oscillateur/oscillateur.h ../vecteur/vecteur.h 

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testintegrateur

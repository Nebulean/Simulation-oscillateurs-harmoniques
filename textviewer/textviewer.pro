# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testtextviewer.cc textviewer.cc ../supportadessin/supportadessin.cc ../pendule/pendule.cc ../ressort/ressort.cc ../systeme/systeme.cc

HEADERS = textviewer.h ../supportadessin/supportadessin.h ../pendule/pendule.h ../ressort/ressort.h ../systeme/systeme.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testtextviewer

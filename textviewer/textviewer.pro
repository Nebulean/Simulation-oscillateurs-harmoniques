# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testtextviewer.cc textviewer.cc ../supportadessin/supportadessin.cc ../dessinable/dessinable.cc ../pendule/pendule.cc ../ressort/ressort.cc ../vecteur/vecteur.cc ../oscillateur/oscillateur.cc ../systeme/systeme.cc

HEADERS = textviewer.h ../supportadessin/supportadessin.h ../dessinable/dessinable.h ../pendule/pendule.h ../ressort/ressort.h ../vecteur/vecteur.h ../oscillateur/oscillateur.h ../systeme/systeme.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testtextviewer

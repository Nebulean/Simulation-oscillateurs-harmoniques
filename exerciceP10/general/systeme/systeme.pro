# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

QMAKE_CXXFLAGS += -std=c++11

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testsysteme.cc systeme.cc ../oscillateur/oscillateur.cc ../dessinable/dessinable.cc ../supportadessin/supportadessin.cc ../vecteur/vecteur.cc ../../text/textviewer.cc ../pendule/pendule.cc ../integrateur/integrateur.cc ../eulercromer/eulercromer.cc

HEADERS = systeme.h ../oscillateur/oscillateur.h ../dessinable/dessinable.h ../supportadessin/supportadessin.h ../vecteur/vecteur.h ../../text/textviewer.h ../pendule/pendule.h ../integrateur/integrateur.h ../eulercromer/eulercromer.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../../../build/

# le nom de l'executable.
TARGET = testsysteme

# pour include facilement
INCLUDEPATH +=  ../dessinable/ \
                ../eulercromer/ \
                ../integrateur/ \
                ../oscillateur/ \
                ../pendule/ \
                ../supportadessin/ \
                ../vecteur/ \
                ../ressort/ \
                ../torsion/ \
                ../../text/

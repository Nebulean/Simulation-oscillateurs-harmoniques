# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -std=c++11

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../../../build/

# le nom de l'executable
TARGET = testchariot

INCLUDEPATH +=  ../oscillateur/ \
                ../vecteur/ \
                ../dessinable/ \
                ../supportadessin/ \
                ../../text/ \
                ../eulercromer/ \
                ../integrateur/ \
                ../pendule/ \
                ../ressort/ \
                ../torsion/ \
                ../systeme/ \
                ../chute/ \

SOURCES +=  testchariot.cc \
            chariot.cc \
            ../oscillateur/oscillateur.cc \
            ../vecteur/vecteur.cc \
            ../dessinable/dessinable.cc \
            ../supportadessin/supportadessin.cc \
            ../../text/textviewer.cc \
            ../eulercromer/eulercromer.cc \
            ../integrateur/integrateur.cc \
            ../pendule/pendule.cc \
            ../ressort/ressort.cc \
            ../torsion/torsion.cc \
            ../systeme/systeme.cc \
            ../chute/chute.cc \

HEADERS +=  chariot.h \
            ../oscillateur/oscillateur.h \
            ../vecteur/vecteur.h \
            ../dessinable/dessinable.h \
            ../supportadessin/supportadessin.h \
            ../../text/textviewer.h \
            ../eulercromer/eulercromer.h \
            ../integrateur/integrateur.h \
            ../pendule/pendule.h \
            ../ressort/ressort.h \
            ../torsion/torsion.h \
            ../systeme/systeme.h \
            ../chute/chute.h \

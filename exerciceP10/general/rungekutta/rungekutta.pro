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
TARGET = testrungekutta

INCLUDEPATH +=  ../integrateur/ \
                ../oscillateur/ \
                ../vecteur/ \
                ../dessinable/ \
                ../supportadessin/ \
                ../../text/ \
                ../pendule/ \
                ../systeme/ \
                ../ressort/ \
                ../torsion/ \
                ../chute/ \
                ../eulercromer/ \

SOURCES +=  testrungekutta.cc \
            rungekutta.cc \
            ../integrateur/integrateur.cc \
            ../oscillateur/oscillateur.cc \
            ../vecteur/vecteur.cc \
            ../dessinable/dessinable.cc \
            ../supportadessin/supportadessin.cc \
            ../../text/textviewer.cc \
            ../pendule/pendule.cc \
            ../systeme/systeme.cc \
            ../ressort/ressort.cc \
            ../torsion/torsion.cc \
            ../chute/chute.cc \
            ../eulercromer/eulercromer.cc \

HEADERS +=  rungekutta.h \
            ../integrateur/integrateur.h \
            ../oscillateur/oscillateur.h \
            ../vecteur/vecteur.h \
            ../dessinable/dessinable.h \
            ../supportadessin/supportadessin.h \
            ../../text/textviewer.h \
            ../pendule/pendule.h \
            ../systeme/systeme.h \
            ../ressort/ressort.h \
            ../torsion/torsion.h \
            ../chute/chute.h \
            ../eulercromer/eulercromer.h \

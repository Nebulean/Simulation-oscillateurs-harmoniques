# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -std=c++11

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../../../build/

# le nom de l'executable, en fonction de la configuration actuelle.

TARGET = testphase

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
                ../chariot/ \
                ../penduledouble/ \
                ../penduleressort/ \
                ../rungekutta/ \

SOURCES +=  testphase.cc \
            phase.cc \
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
            ../chariot/chariot.cc \
            ../penduledouble/penduledouble.cc \
            ../penduleressort/penduleressort.cc \
            ../rungekutta/rungekutta.cc \

HEADERS +=  phase.h \
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
            ../chariot/chariot.h \
            ../penduledouble/penduledouble.h \
            ../penduleressort/penduleressort.h \
            ../rungekutta/rungekutta.h \

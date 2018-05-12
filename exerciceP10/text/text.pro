# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

QMAKE_CXXFLAGS += -std=c++11

# LIBS += -L../general -lgeneral
# PRE_TARGETDEPS += ../general/libgeneral.a


INCLUDEPATH +=  ../general/dessinable/ \
                ../general/eulercromer/ \
                ../general/integrateur/ \
                ../general/oscillateur/ \
                ../general/pendule/ \
                ../general/ressort/ \
                ../general/supportadessin/ \
                ../general/systeme/ \
                ../general/torsion/ \
                ../general/vecteur/ \
                ../general/chariot/ \
                ../general/chute/ \
                ../general/penduledouble/ \
                ../general/newmark/ \
                ../general/rungekutta/ \

SOURCES += \
    main_text.cc \
    textviewer.cc \
    ../general/dessinable/dessinable.cc \
    ../general/eulercromer/eulercromer.cc \
    ../general/integrateur/integrateur.cc \
    ../general/oscillateur/oscillateur.cc \
    ../general/pendule/pendule.cc \
    ../general/ressort/ressort.cc \
    ../general/supportadessin/supportadessin.cc \
    ../general/systeme/systeme.cc \
    ../general/torsion/torsion.cc \
    ../general/vecteur/vecteur.cc \
    ../general/chariot/chariot.cc \
    ../general/chute/chute.cc \
    ../general/penduledouble/penduledouble.cc \
    ../general/newmark/newmark.cc \
    ../general/rungekutta/rungekutta.cc \

HEADERS += \
    textviewer.h \
    ../general/dessinable/dessinable.h \
    ../general/eulercromer/eulercromer.h \
    ../general/integrateur/integrateur.h \
    ../general/oscillateur/oscillateur.h \
    ../general/pendule/pendule.h \
    ../general/ressort/ressort.h \
    ../general/supportadessin/supportadessin.h \
    ../general/systeme/systeme.h \
    ../general/torsion/torsion.h \
    ../general/vecteur/vecteur.h \
    ../general/chariot/chariot.h \
    ../general/chute/chute.h \
    ../general/penduledouble/penduledouble.h \
    ../general/newmark/newmark.h \
    ../general/rungekutta/rungekutta.h \



# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../../build/

# le nom de l'executable.
TARGET = simulationText

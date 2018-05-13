QMAKE_CXXFLAGS += -std=c++11

# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

TEMPLATE = lib

CONFIG = staticlib

OBJECTS_DIR = ../../build/


SOURCES += \
  chariot/chariot.cc \
  chute/chute.cc \
  dessinable/dessinable.cc \
  eulercromer/eulercromer.cc \
  integrateur/integrateur.cc \
  newmark/newmark.cc \
  oscillateur/oscillateur.cc \
  pendule/pendule.cc \
  penduledouble/penduledouble.cc \
  ressort/ressort.cc \
  rungekutta/rungekutta.cc \
  supportadessin/supportadessin.cc \
  systeme/systeme.cc \
  torsion/torsion.cc \
  vecteur/vecteur.cc \

HEADERS += \
  chariot/chariot.h \
  chute/chute.h \
  dessinable/dessinable.h \
  eulercromer/eulercromer.h \
  integrateur/integrateur.h \
  newmark/newmark.h \
  oscillateur/oscillateur.h \
  pendule/pendule.h \
  penduledouble/penduledouble.h \
  ressort/ressort.h \
  rungekutta/rungekutta.h \
  supportadessin/supportadessin.h \
  systeme/systeme.h \
  torsion/torsion.h \
  vecteur/vecteur.h \

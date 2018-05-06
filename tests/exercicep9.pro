# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = exercicep9.cc ../systeme/systeme.cc ../textviewer/textviewer.cc ../pendule/pendule.cc ../ressort/ressort.cc ../eulercromer/eulercromer.cc ../oscillateur/oscillateur.cc ../vecteur/vecteur.cc ../dessinable/dessinable.cc ../torsion/torsion.cc

HEADERS = ../systeme/systeme.h ../textviewer/textviewer.h ../pendule/pendule.h ../ressort/ressort.h ../eulercromer/eulercromer.h ../oscillateur/oscillateur.h ../vecteur/vecteur.h ../dessinable/dessinable.h ../torsion/torsion.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = exercicep9

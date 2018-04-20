# les compilateurs utilisés
QMAKE_CC = g++
QMAKE_CXX = g++

# Utile sur MacOS, permet de ne pas avoir de .app lors de la compilation, mais un simple executable.
CONFIG -= app_bundle

SOURCES = testsysteme.cc systeme.cc ../oscillateur/oscillateur.cc ../dessinable/dessinable.cc ../supportadessin/supportadessin.cc ../vecteur/vecteur.cc ../textviewer/textviewer.cc ../pendule/pendule.cc ../integrateur/integrateur.cc ../eulercromer/eulercromer.cc

HEADERS = systeme.h ../oscillateur/oscillateur.h ../dessinable/dessinable.h ../supportadessin/supportadessin.h ../vecteur/vecteur.h ../textviewer/textviewer.h ../pendule/pendule.h ../integrateur/integrateur.h ../eulercromer/eulercromer.h

# le dossier de sortie pour tous les fichiers .o de la compilation.
# Ca permet de ne pas avoir trop de bordel dans le dossier courant.
OBJECTS_DIR = ../build/

# le nom de l'executable.
TARGET = testsysteme

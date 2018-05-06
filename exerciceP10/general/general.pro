QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = lib

CONFIG = staticlib

SOURCES = contenu.cc

HEADERS += \
    contenu.h \
    dessinable.h \
    support_a_dessin.h

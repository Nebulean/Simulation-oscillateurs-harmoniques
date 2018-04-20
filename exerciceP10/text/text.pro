QMAKE_CXXFLAGS += -std=c++11

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc
    
HEADERS += \
    ../general/contenu.h \
    text_viewer.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h

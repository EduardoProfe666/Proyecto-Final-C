TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Logica/logica.c \
    Interfaz/inicio.c \
    Interfaz/consola.c \
    Interfaz/interfazPrincipal.c \
    Logica/validaciones.c \
    Interfaz/reportes.c \
    Interfaz/introduccionManual.c \
    Interfaz/preguntasAlUsuario.c \
    Interfaz/salida.c \
    Interfaz/orqui.c

OTHER_FILES +=

HEADERS += \
    Logica/definiciones.h \
    Logica/logica.h \
    Logica/estructura.h \
    Interfaz/inicio.h \
    Interfaz/consola.h \
    Interfaz/interfazPrincipal.h \
    Logica/validaciones.h \
    Interfaz/reportes.h \
    Interfaz/introduccionManual.h \
    Interfaz/preguntasAlUsuario.h \
    Interfaz/salida.h \
    Interfaz/orqui.h


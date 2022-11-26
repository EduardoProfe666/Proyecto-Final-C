#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "Logica/definiciones.h"

struct datosPorAnyoCompeticion{
    int numeroAnyo;
    char nombreResponsable[MAX_LONG_CADENA_CARACTERES];
    int cantidadMedallas;
    int cantParticipantes;
    struct{
        char nombre[MAX_LONG_CADENA_CARACTERES];
        char sexo;
        char deporte[MAX_LONG_CADENA_CARACTERES];
    }participantesAnyo[CANT_MAX_PARTICIPANTES];
};

struct baseDeDatos{
    char baseNombres[CANT_DATOS_PERSONALES_BD][MAX_NOMBRE_APELLIDO_DEPORTE_BD];
    char baseSexo[CANT_DATOS_PERSONALES_BD];
    char baseApellidos[CANT_DATOS_PERSONALES_BD][MAX_NOMBRE_APELLIDO_DEPORTE_BD];
    char baseDeportes[CANT_MAX_DEPORTES][MAX_NOMBRE_APELLIDO_DEPORTE_BD];
    int cantidadDeportesAlmacenados; //Se hizo asi pq el usuario puede luego agregar o eliminar deportes
};

typedef struct datosPorAnyoCompeticion DatosAnyo;
typedef struct baseDeDatos BD;

#endif // ESTRUCTURA_H

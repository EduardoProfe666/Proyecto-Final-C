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

struct piscinaDeDatos{
    char piscinaNombres[CANT_DATOS_PERSONALES_PD][MAX_NOMBRE_APELLIDO_DEPORTE_PD];
    char piscinaSexo[CANT_DATOS_PERSONALES_PD];
    char piscinaApellidos[CANT_DATOS_PERSONALES_PD][MAX_NOMBRE_APELLIDO_DEPORTE_PD];
    char piscinaDeportes[CANT_MAX_DEPORTES][MAX_NOMBRE_APELLIDO_DEPORTE_PD];
    int cantidadDeportesAlmacenados; //Se hizo asi pq el usuario puede luego agregar o eliminar deportes
};

typedef struct datosPorAnyoCompeticion DatosAnyo;
typedef struct piscinaDeDatos PD;

#endif // ESTRUCTURA_H

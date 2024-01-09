#include <windows.h>
#include "Logica/estructura.h"


void inicializarBaseDeDatos(PD*);
void inicializarDatos(DatosAnyo[],PD,int*);
int determinarAnyoActual();
int determinarAnyoMayorMedallas(DatosAnyo[],int);
int determinarTotalAnyoMayorMujeres(DatosAnyo[],int);
float determinarPorcentajeAnualMedallasParticipantes(int,int);

void aleatorizarCantidadAnyos(int*);
void rellenarNumerosAnyos(DatosAnyo[],int);
int aleatorizarCantidadParticipantes();
int aleatorizarCantidadMedallas(int);
char aleatorizarNombre(PD,char[]);
void aleatorizarDeporte(PD,char[]);
void rellenarDatosPersonales(PD,DatosAnyo*,int);

void eliminarDeporte(PD*,COORD);

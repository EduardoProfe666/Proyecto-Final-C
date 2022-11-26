#include <windows.h>
#include "Logica/estructura.h"


void inicializarBaseDeDatos(BD*);
void inicializarDatos(DatosAnyo[],BD,int*);
int determinarAnyoActual();
int determinarAnyoMayorMedallas(DatosAnyo[],int);
int determinarTotalAnyoMayorMujeres(DatosAnyo[],int);
float determinarPorcentajeAnualMedallasParticipantes(int,int);

void aleatorizarCantidadAnyos(int*);
void rellenarNumerosAnyos(DatosAnyo[],int);
int aleatorizarCantidadParticipantes();
int aleatorizarCantidadMedallas(int);
char aleatorizarNombre(BD,char[]);
void aleatorizarDeporte(BD,char[]);
void rellenarDatosPersonales(BD,DatosAnyo*,int);

void eliminarDeporte(BD*,COORD);

#ifndef CONSOLA_H
#define CONSOLA_H
#include <windows.h>
#include <stdbool.h>

void cambiarVisibilidadCursor(bool);
void moverCursor(int,int);
void modificarTamanyoBuffer(int, int);
void imprimirExtremosMarco(int,int,int,int);
void imprimirCuerpoMarco(int,int,int);
void imprimirUnionCuerpoExtremosMarco(int,int,int);
void imprimirMarcoGeneral(int,int,COORD,int);
void prepararConsola();
void modificarColor(int);
void imprimirMarcoSimple(COORD);

#endif // CONSOLA_H

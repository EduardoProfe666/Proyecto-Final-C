#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Interfaz/inicio.h"
#include "Interfaz/consola.h"
#include "Interfaz/interfazPrincipal.h"
#include "Interfaz/salida.h"
#include "Logica/definiciones.h"
#include "Logica/estructura.h"
#include "Logica/logica.h"                    //Tarea Final de IP
                                             //Eduardo Alejandro Gonzalez Martell
                                            //G-11 #13
int main(void){
    //Esta sección de código es para determinar las coordenadas de inicio del marco
    int x=((ANCHO_VENTANA_CONSOLA/(GetSystemMetrics(SM_CXSCREEN)<=1280  ? 0.94 : 1.063))-LONG_ANCHO_MARCO*8)/16;
    int y=((ALTO_VENTANA_CONSOLA/16)-LONG_ALTO_MARCO)/4;
    COORD posicionMarco={x-(GetSystemMetrics(SM_CXSCREEN)<=1280 ? x/16 : -x/3),y+y/2};

    DatosAnyo anyoCompeticion[CANTIDAD_ANYOS_MAX]={{0,{"0"},0,0,{{ {"0"},'0',{"0"} }} }};
    PD piscinaDatos;

    inicializarBaseDeDatos(&piscinaDatos);
    prepararConsola();
    inicio(posicionMarco);

    if(CANTIDAD_ANYOS_MAX>=determinarAnyoActual()-ANYO_FUNDACION_FAC_INF+1)
        interfazPrincipal(anyoCompeticion, piscinaDatos, posicionMarco);
    else{
        imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("El sistema no puede soportar el almacenamiento de  m\240s datos. Contacte con el soporte t\202cnico");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("para m\240s informaci\242n.");
        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(BLANCO);
        system("pause");
        system("cls");
    }
    salida(posicionMarco);

    return 0;
}

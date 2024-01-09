#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Interfaz/consola.h"
#include "Logica/definiciones.h"

void borrarCaracter(int x,int y){
    _setmode(_fileno(stdout),_O_TEXT);
    moverCursor(x,y);
    printf(" ");
}

void imprimirCaracter(int x,int y, int tipoCaracter){
    _setmode(_fileno(stdout),_O_U16TEXT);
    moverCursor(x,y);
    if(tipoCaracter==0)
        wprintf(L"\x058D");  //Circulo Relleno Continuo
    else
        wprintf(L"\x25CC");  //Circulo Discontinuo
}

void imprimirCargandoAnimacion(COORD posicionMarco, int tipoCaracter){
    _setmode(_fileno(stdout),_O_TEXT);
    moverCursor((LONG_ANCHO_MARCO-11)/2+7+posicionMarco.X,posicionMarco.Y+21);
    switch (tipoCaracter) {
    case 0:
        printf("%c",124);  // (|)
        break;
    case 1:
        printf("%c",47);   // (/)
        break;
    case 2:
        printf("%c",45);   // (-)
        break;
    case 3:
        printf("%c",92);   // (\)
        break;
    }
}

void animacionCargando(COORD posicionMarco){
    int i;
    int pos_x_centrado=(LONG_ANCHO_MARCO-11)/2+1+posicionMarco.X;

    cambiarVisibilidadCursor(false);
    modificarColor(VERDE);
    for(i=0;i<CANT_ANIMACIONES;i++){
        imprimirCaracter(pos_x_centrado+4,posicionMarco.Y+19,0);
        imprimirCaracter(pos_x_centrado+2,posicionMarco.Y+20,1);
        imprimirCaracter(pos_x_centrado+1,posicionMarco.Y+21,1);
        imprimirCaracter(pos_x_centrado+2,posicionMarco.Y+22,2);
        imprimirCargandoAnimacion(posicionMarco,0);
        borrarCaracter(pos_x_centrado+4,posicionMarco.Y+23);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+6,posicionMarco.Y+19,0);
        imprimirCaracter(pos_x_centrado+4,posicionMarco.Y+19,1);
        imprimirCargandoAnimacion(posicionMarco,1);
        borrarCaracter(pos_x_centrado+2,posicionMarco.Y+22);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+8,posicionMarco.Y+19,0);
        imprimirCaracter(pos_x_centrado+6,posicionMarco.Y+19,1);
        imprimirCargandoAnimacion(posicionMarco,2);
        borrarCaracter(pos_x_centrado+1,posicionMarco.Y+21);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+10,posicionMarco.Y+20,0);
        imprimirCaracter(pos_x_centrado+8,posicionMarco.Y+19,1);
        imprimirCargandoAnimacion(posicionMarco,3);
        borrarCaracter(pos_x_centrado+2,posicionMarco.Y+20);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+11,posicionMarco.Y+21,0);
        imprimirCaracter(pos_x_centrado+10,posicionMarco.Y+20,1);
        imprimirCargandoAnimacion(posicionMarco,0);
        borrarCaracter(pos_x_centrado+4,posicionMarco.Y+19);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+10,posicionMarco.Y+22,0);
        imprimirCaracter(pos_x_centrado+11,posicionMarco.Y+21,1);
        imprimirCargandoAnimacion(posicionMarco,1);
        borrarCaracter(pos_x_centrado+6,posicionMarco.Y+19);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+8,posicionMarco.Y+23,0);
        imprimirCaracter(pos_x_centrado+10,posicionMarco.Y+22,1);
        imprimirCargandoAnimacion(posicionMarco,2);
        borrarCaracter(pos_x_centrado+8,posicionMarco.Y+19);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+6,posicionMarco.Y+23,0);
        imprimirCaracter(pos_x_centrado+8,posicionMarco.Y+23,1);
        imprimirCargandoAnimacion(posicionMarco,3);
        borrarCaracter(pos_x_centrado+10,posicionMarco.Y+20);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+4,posicionMarco.Y+23,0);
        imprimirCaracter(pos_x_centrado+6,posicionMarco.Y+23,1);
        imprimirCargandoAnimacion(posicionMarco,0);
        borrarCaracter(pos_x_centrado+11,posicionMarco.Y+21);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+2,posicionMarco.Y+22,0);
        imprimirCaracter(pos_x_centrado+4,posicionMarco.Y+23,1);
        imprimirCargandoAnimacion(posicionMarco,1);
        borrarCaracter(pos_x_centrado+8,posicionMarco.Y+23);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+1,posicionMarco.Y+21,0);
        imprimirCaracter(pos_x_centrado+2,posicionMarco.Y+22,1);
        imprimirCargandoAnimacion(posicionMarco,2);
        borrarCaracter(pos_x_centrado+10,posicionMarco.Y+22);
        Sleep(RETARDO_SALIDA);

        imprimirCaracter(pos_x_centrado+2,posicionMarco.Y+20,0);
        imprimirCaracter(pos_x_centrado+1,posicionMarco.Y+21,1);
        imprimirCargandoAnimacion(posicionMarco,3);
        borrarCaracter(pos_x_centrado+6,posicionMarco.Y+23);
        Sleep(RETARDO_SALIDA);
    }

    _setmode(_fileno(stdout),_O_TEXT);
    printf("\a");
    modificarColor(BLANCO);
    cambiarVisibilidadCursor(true);
}

void imprimirLogoFEUsalida(COORD posicionMarco){
    int logoColores[][39]={
        {0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,1,1},
        {0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1},
        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1},
        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1},
        {0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1},
        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1},
        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1},
        {0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
        {0}
    };
    int i, j;

    for(i=0;i<12;i++){
        moverCursor((LONG_ANCHO_MARCO-39)/2+1+posicionMarco.X,posicionMarco.Y+1+i);
        for(j=0;j<=38;j++){
            logoColores[i][j]==0 ? modificarColor(ROJO): modificarColor(BLANCO);
            printf("\xDB");
        }
        printf("\n");
    }
    modificarColor(REINICIAR_COLOR);
}

void salida(COORD posicionMarco){
    modificarTamanyoBuffer(BUFFER_SIMPLE_X,BUFFER_SIMPLE_Y);
    imprimirMarcoSimple(posicionMarco);
    imprimirLogoFEUsalida(posicionMarco);

    modificarColor(BLANCO);
    moverCursor((LONG_ANCHO_MARCO-16)/2+1+posicionMarco.X,posicionMarco.Y+17);
    printf("CERRANDO SISTEMA");

    animacionCargando(posicionMarco);

    system("cls");
    Sleep(ESPERA_SALIDA);
    system("cls"); //Para que coja bien el retardo
}

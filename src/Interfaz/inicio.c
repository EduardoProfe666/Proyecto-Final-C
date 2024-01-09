#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "Logica/definiciones.h"
#include "Interfaz/consola.h"

void imprimirLogoFEU(COORD posicionMarco,int retardoImpresion){
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

    cambiarVisibilidadCursor(false);
    for(i=0;i<12;i++){  //Es necesario imprimir el salto de línea al final de la función pues este posibilita
        if(i%2==1){     //que se impriman correctamente los caracteres
            moverCursor((LONG_ANCHO_MARCO+41)/2+1+posicionMarco.X,posicionMarco.Y+1+i);
            for(j=38;j>=0;j--){
                printf("\b\b");
                logoColores[i][j]==0 ? modificarColor(ROJO): modificarColor(BLANCO);
                printf("\xDB");
                Sleep(!kbhit() ? retardoImpresion : 0);
            }
        }
        else{
            moverCursor((LONG_ANCHO_MARCO-39)/2+1+posicionMarco.X,posicionMarco.Y+1+i);
            for(j=0;j<=38;j++){
                logoColores[i][j]==0 ? modificarColor(ROJO): modificarColor(BLANCO);
                printf("\xDB");
                Sleep(!kbhit() ? retardoImpresion : 0);
            }
        }
        printf("\n");
    }
    modificarColor(REINICIAR_COLOR);
    cambiarVisibilidadCursor(true);
}

void imprimirBienvenidaYUsuarioContrasenyaInicio(COORD posicionMarco){
    moverCursor((LONG_ANCHO_MARCO-81)/2+1+posicionMarco.X,posicionMarco.Y+15);
    printf("BIENVENIDO/A AL SISTEMA DE DEPORTES DE LA FEU-CUJAE DE LA FACULTAD DE INFORM%cTICA",-75);
    moverCursor((LONG_ANCHO_MARCO-23)/2+1+posicionMarco.X,posicionMarco.Y+17);
    printf("Usuario:");
    moverCursor((LONG_ANCHO_MARCO-23)/2+1+posicionMarco.X,posicionMarco.Y+18);
    printf("Contrase%ca:", 164);
}

void animacionUsuarioContrasenyaInicio(COORD posicionMarco){
    int i;
    char nombreUsuario[]={NOMBRE_USUARIO};
    char contrasenya[]={CONTRASENYA};

    Sleep(ESPERA_VISUALIZACION_INICIO);

    moverCursor((LONG_ANCHO_MARCO-5)/2+1+posicionMarco.X,posicionMarco.Y+17);
    for(i=0;i<(int)strlen(nombreUsuario);i++){
        printf("%c", nombreUsuario[i]);
        Sleep(RETARDO_UC_INICIO);
    }

    moverCursor((LONG_ANCHO_MARCO+1)/2+1+posicionMarco.X,posicionMarco.Y+18);
    for(i=0;i<(int)strlen(contrasenya);i++){
        printf("%c", contrasenya[i]);
        Sleep(RETARDO_UC_INICIO);
    }
}

void animacionCargandoInicio(COORD posicionMarco){
    int i,j,k=(LONG_ANCHO_MARCO-22)/2+1+posicionMarco.X;
    int marcoProgreso[][21]={
        {201,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,203,205,187},
        {186,0,186,0,186,0,186,0,186,0,186,0,186,0,186,0,186,0,186,0,186},
        {200,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,202,205,188}
    };

    cambiarVisibilidadCursor(false);
    modificarColor(BLANCO);
    moverCursor((LONG_ANCHO_MARCO-24)/2+1+posicionMarco.X,posicionMarco.Y+21);
    printf("CARGANDO SISTEMA:");

    modificarColor(REINICIAR_COLOR);
    for(i=0;i<3;i++){
        moverCursor(k,posicionMarco.Y+22+i);
        for(j=0;j<21;j++){
            if(marcoProgreso[i][j]==0)
                printf(" ");
            else
                printf("%c", marcoProgreso[i][j]);
        }
    }

    modificarColor(BLANCO);
    for(i=1;i<=100;i++){
        if(i%10==0 && i!=0){
            moverCursor(k+i/10,posicionMarco.Y+23);
            modificarColor(VERDE);
            printf("\xDB");
            modificarColor(BLANCO);
            k+=1;
        }
        moverCursor((LONG_ANCHO_MARCO+12)/2+1+posicionMarco.X,posicionMarco.Y+21);
        printf("%4d%%", i);
        Sleep(RETARDO_CARGA_INICIO);
    }

    Sleep(ESPERA_VISUALIZACION_CARGA);
    modificarColor(REINICIAR_COLOR);
    cambiarVisibilidadCursor(true);
}

void imprimirEsperaSistemaCargado(COORD posicionMarco){
    modificarColor(BLANCO);
    moverCursor((LONG_ANCHO_MARCO-15)/2+1+posicionMarco.X,posicionMarco.Y+17);
    printf("SISTEMA CARGADO\a");

    modificarColor(REINICIAR_COLOR);
    moverCursor((LONG_ANCHO_MARCO-41)/2+1+posicionMarco.X,posicionMarco.Y+22);
    system("pause");
}

void inicio(COORD posicionMarco){
    modificarTamanyoBuffer(BUFFER_SIMPLE_X,BUFFER_SIMPLE_Y);
    imprimirMarcoSimple(posicionMarco);
    imprimirLogoFEU(posicionMarco,RETARDO_LOGO_FEU);
    modificarColor(BLANCO);
    imprimirBienvenidaYUsuarioContrasenyaInicio(posicionMarco);
    animacionUsuarioContrasenyaInicio(posicionMarco);
    modificarColor(REINICIAR_COLOR);
    animacionCargandoInicio(posicionMarco);
    system("cls");
    imprimirMarcoSimple(posicionMarco);
    imprimirLogoFEU(posicionMarco,0);
    imprimirEsperaSistemaCargado(posicionMarco);
}

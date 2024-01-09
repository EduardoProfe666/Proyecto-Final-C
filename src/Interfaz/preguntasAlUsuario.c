#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Logica/definiciones.h"
#include "Logica/validaciones.h"
#include "Logica/estructura.h"
#include "Logica/logica.h"
#include "Interfaz/consola.h"

int preguntarSalida(COORD posicionMarco){
    char respTemp[TAM_CHAR_VAR_VALIDAR];
    int respuesta;
    bool entradaValidada;
    do{
        imprimirMarcoGeneral(0,1,posicionMarco,LONG_ALTO_MARCO);

        moverCursor((LONG_ANCHO_MARCO-19)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Salida del Programa");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("Y/y -> Si quiere salir del programa");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("N/n -> Si quiere continuar la ejecuci\242n del programa");

        modificarColor(REINICIAR_COLOR);
        moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        entradaValidada=validarYN(respTemp);
        if(entradaValidada){
            if(respTemp[0]=='Y'||respTemp[0]=='y')
                respuesta=0; //Se pone así debido a como fue planteado en interfazPrincipal.c la condición de salida del do/while
            else
                respuesta=1;
        }
        else{
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir un caracter: Y/y o N/n. En dependencia de su selecci\242n, el programa ejecutar\240");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("la acci\242n que le  corresponde el caracter introducido. Tome como gu\241a la lista otorgada en el");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("men\243 de salida del programa.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }
    }while(!entradaValidada);

    return respuesta;
}

bool preguntarDatosExistentesAdv(COORD posicionMarco,int formatoAdvertencia){
    //formatoAdvertencia:0->Generación Automática; 1->Introducción Manual; 2->Modificar Deporte
    char respTemp[TAM_CHAR_VAR_VALIDAR];
    bool resp=false;
    bool entradaValidada;
    do{
        imprimirMarcoGeneral(3,1,posicionMarco,LONG_ALTO_MARCO);

        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Existen datos en el sistema. La ejecuci\242n de la ");
        if(formatoAdvertencia==0)
            printf("generaci\242n  de  datos  autom\240tica  provoca");
        else if(formatoAdvertencia==1)
            printf("introducci\242n manual de datos puede provocar");
        else
            printf(" modificaci\242n  de  los  deportes  provoca ");
        printf(" la");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("p\202rdida de los datos existentes. %cDesea continuar de todas formas?", -88);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("Y/y Si desea ");
        if(formatoAdvertencia==0)
            printf("generar los datos de forma autom\240tica");
        else if(formatoAdvertencia==1)
            printf("introducir los datos de forma manual");
        else
            printf("modificar los deportes de la base de datos");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("N/n Si desea mantener los datos existentes");
        modificarColor(REINICIAR_COLOR);

        moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        entradaValidada=validarYN(respTemp);
        if(entradaValidada){
            if(respTemp[0]=='Y'||respTemp[0]=='y')
                resp=true;
        }
        else{
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir un caracter: Y/y o N/n. En dependencia de su selecci\242n, el programa ejecutar\240");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("la  acci\242n que le corresponde  el caracter  introducido. Tome como gu\241a la lista otorgada  en");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("el men\243 de advertencia de ");
            if(formatoAdvertencia==0)
                printf("generaci\242n autom\240tica.");
            else
                printf("introducci\242n manual.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }
    }while(!entradaValidada);

    return resp;
}

int preguntarAnyo(DatosAnyo datosAnyo[],int cantidadAnyos,COORD posicionMarco){
    int anyoPos;
    char anyoPosChar[TAM_CHAR_VAR_VALIDAR];
    int i,k=0;
    bool numeroValidado;

    do{
        k++;

        if(k>1){
            k=1;
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 1 y %d. En dependencia de  su selecci\242n, el programa",cantidadAnyos);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que  le  corresponde  el n\243mero  introducido. Tome  como gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de escoger a%co.",164);
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }

        imprimirMarcoGeneral(1,1,posicionMarco,cantidadAnyos+8);

        moverCursor((LONG_ANCHO_MARCO-11)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Escoger A%co",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Seleccione  uno de  los  a%cos disponibles  en la base  de datos, marcando  la opci\242n  listada",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("correspondiente:");

        for(i=0;i<cantidadAnyos;i++){
            moverCursor(posicionMarco.X+4,5+i+posicionMarco.Y);
            printf("%-2d -> %d",i+1,datosAnyo[i].numeroAnyo);
        }

        moverCursor(posicionMarco.X+5,cantidadAnyos+7+posicionMarco.Y);
        modificarColor(REINICIAR_COLOR);

        fflush(stdin);
        fgets(anyoPosChar,sizeof(anyoPosChar),stdin);

        numeroValidado=validarNumeroCorrecto(anyoPosChar,cantidadAnyos,1);
        if(numeroValidado)
            anyoPos=atoi(anyoPosChar);

    }while(!numeroValidado);

    return anyoPos-1;
}

int preguntarDeporte(PD piscinaDatos,COORD posicionMarco){
    int deportePos;
    char deportePosChar[TAM_CHAR_VAR_VALIDAR];
    bool numeroValidado;
    int i,k=0;

    do{
        k++;

        if(k>1){
            k=1;
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 1 y %d. En  dependencia de su  selecci\242n, el programa",piscinaDatos.cantidadDeportesAlmacenados);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que  le corresponde  el  n\243mero  introducido. Tome  como gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de escoger deporte.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }

        imprimirMarcoGeneral(1,1,posicionMarco,piscinaDatos.cantidadDeportesAlmacenados+8);

        moverCursor((LONG_ANCHO_MARCO-11)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Escoger Deporte");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Seleccione uno de  los deportes  disponibles en la  base de datos, marcando la opci\242n listada");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("correspondiente:");

        for(i=0;i<piscinaDatos.cantidadDeportesAlmacenados;i++){
            moverCursor(posicionMarco.X+4,5+i+posicionMarco.Y);
            printf("%-2d -> %s",i+1, piscinaDatos.piscinaDeportes[i]);
        }

        moverCursor(posicionMarco.X+5,piscinaDatos.cantidadDeportesAlmacenados+7+posicionMarco.Y);
        modificarColor(REINICIAR_COLOR);

        fflush(stdin);
        fgets(deportePosChar,sizeof(deportePosChar),stdin);

        numeroValidado=validarNumeroCorrecto(deportePosChar,piscinaDatos.cantidadDeportesAlmacenados,1);
        if(numeroValidado)
            deportePos=atoi(deportePosChar);

    }while(!numeroValidado);

    return deportePos-1;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Logica/logica.h>
#include "Logica/definiciones.h"
#include "Logica/estructura.h"
#include "Logica/validaciones.h"
#include "Interfaz/consola.h"
#include "Interfaz/reportes.h"
#include "Interfaz/preguntasAlUsuario.h"
#include "Interfaz/introduccionManual.h"
#include "Interfaz/orqui.h"

void comunicarInicializacionDatos(COORD posicionMarco){
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);

    moverCursor((LONG_ANCHO_MARCO-30)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Generaci\242n Autom\240tica de Datos");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("Los datos fueron generados correctamente.");
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void comunicarDatosNoInicializadosErr(COORD posicionMarco){
    imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("No existen datos en el sistema. Debe introducirlos  manualmente o generarlos de forma autom\240-");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
    printf("tica.");
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void interfazPrincipal(DatosAnyo datosAnyo[], PD piscinaDatos, COORD posicionMarco){
    char respTemp[TAM_CHAR_VAR_COMANDO];
    int respuesta;
    int cantidadAnyos=0;
    bool datosExistentes=false;

    do{
        bool respuestaTemp=true;
        respuesta=-1;

        imprimirMarcoGeneral(0,1,posicionMarco,LONG_ALTO_MARCO);

        moverCursor((LONG_ANCHO_MARCO-14)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Men\243 Principal");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("0-. Salir del programa");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("1-. Generar datos de forma autom\240tica.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("2-. Introducir datos manualmente.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("3-. Mostrar reporte anual de todos los datos almacenados.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
        printf("4-. Mostrar a%co con mayor cantidad de medallas ganadas.", 164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+9);
        printf("5-. Mostrar reporte anual del porcentaje de medallas obtenidas por participantes.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+10);
        printf("6-. Mostrar total de a%cos donde la cifra de mujeres supere a la de los hombres.", 164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+11);
        printf("7-. Mostrar los participantes dado un a%co y deporte espec\241fico.", 164);

        modificarColor(REINICIAR_COLOR);
        moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        bool comandoOrqui=validarComandoOrqui(respTemp);
        if(comandoOrqui)
            orqui(posicionMarco);
        else{
            bool numeroValidado=validarNumeroCorrecto(respTemp,7,0);
            if(numeroValidado)
                respuesta=atoi(respTemp);

            switch(respuesta){
            case 0:
                respuesta = preguntarSalida(posicionMarco);
                break;
            case 1:
                if(datosExistentes)
                    respuestaTemp=preguntarDatosExistentesAdv(posicionMarco,0);

                if(respuestaTemp){
                    inicializarDatos(datosAnyo, piscinaDatos, &cantidadAnyos);
                    comunicarInicializacionDatos(posicionMarco);
                    datosExistentes=true;
                }
                break;
            case 2:
                if(datosExistentes)
                    respuestaTemp=preguntarDatosExistentesAdv(posicionMarco,1);

                if(respuestaTemp){
                    introducirDatosUsuario(datosAnyo,&piscinaDatos,&cantidadAnyos,&datosExistentes,posicionMarco);
                }
                break;
            case 3:
                if(datosExistentes)
                    mostrarReporteAnual(datosAnyo,cantidadAnyos,posicionMarco);
                else
                    comunicarDatosNoInicializadosErr(posicionMarco);
                break;
            case 4:
                if(datosExistentes)
                    mostrarAnyoMayorMedallas(datosAnyo,cantidadAnyos,posicionMarco);
                else
                    comunicarDatosNoInicializadosErr(posicionMarco);
                break;
            case 5:
                if(datosExistentes)
                    mostrarPorcentajeAnualMedallasParticipantes(datosAnyo, cantidadAnyos,posicionMarco);
                else
                    comunicarDatosNoInicializadosErr(posicionMarco);
                break;
            case 6:
                if(datosExistentes)
                    mostrarAnyosMayoresMujeres(datosAnyo, cantidadAnyos,posicionMarco);
                else
                    comunicarDatosNoInicializadosErr(posicionMarco);
                break;
            case 7:
                if(datosExistentes)
                    mostrarReporteParticipantesDadoAnyoDeporte(datosAnyo,piscinaDatos,cantidadAnyos,posicionMarco);
                else
                    comunicarDatosNoInicializadosErr(posicionMarco);
                break;
            default:
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir  un n\243mero entero  entre 0 y 7. En dependencia  de su selecci\242n, el  programa");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("ejecutar\240  la acci\242n  que le  corresponde  el n\243mero  introducido. Tome  como  gu\241a  la lista");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                printf("otorgada en el men\243 principal.");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
                break;
            }
        }
    }while(respuesta != 0);
    system("cls");
}

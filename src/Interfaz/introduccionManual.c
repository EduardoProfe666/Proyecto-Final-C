#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include "Logica/definiciones.h"
#include "Logica/estructura.h"
#include "Logica/logica.h"
#include "Logica/validaciones.h"
#include "Interfaz/introduccionManual.h"
#include "Interfaz/preguntasAlUsuario.h"
#include "Interfaz/consola.h"
#include "Interfaz/reportes.h"

void comunicarMaximoDeportesAlcanzadoError(COORD posicionMarco){
    imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("El m\240ximo de deportes ha sido alcanzado, por lo que no puede efectuarse dicha operaci\242n.");
    moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void comunicarMinimoDeportesAlcanzadoError(COORD posicionMarco){
    imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("El m\241nimo de deportes ha sido alcanzado, por lo que no puede efectuarse dicha operaci\242n.");
    moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void comunicarOperacionExito(COORD posicionMarco){
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor((LONG_ANCHO_MARCO-17)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Operaci\242n Exitosa");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("La operaci\242n fue efectuada con \202xito.");
    moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void agregarDeporte(PD *piscinaDatos,COORD posicionMarco){
    bool deporteValidado=false;
    char respTemp[MAX_LONG_CADENA_CARACTERES];

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-13)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Nuevo Deporte");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca el nombre del nuevo deporte.");

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        deporteValidado=validarNombre(respTemp);
        if(deporteValidado)
            deporteValidado=validarRepeticionDeporte(*piscinaDatos,respTemp);
        if(deporteValidado){
            sprintf(piscinaDatos->piscinaDeportes[piscinaDatos->cantidadDeportesAlmacenados],respTemp);
            piscinaDatos->cantidadDeportesAlmacenados++;
        }
        else{
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir un nombre de deporte v\240lido. El nombre debe  tener como m\240ximo ");
            modificarColor(VERDE);
            printf("%d",MAX_LONG_CADENA_CARACTERES-1);
            modificarColor(BLANCO);
            printf(" caracteres;");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("no debe comenzar con espacios vac\241os o estar vac\241o y no debe  contener d\241gitos. No debe exis-");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("tir en el sistema.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }
    }while(!deporteValidado);
}

void modificarDeporte(PD *piscinaDatos,COORD posicionMarco){
    int posDeporte=preguntarDeporte(*piscinaDatos,posicionMarco);
    bool deporteValidado=false;
    char respTemp[MAX_LONG_CADENA_CARACTERES];

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-17)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Modificar Deporte");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca el nombre del deporte que sustituye a ");
        modificarColor(VERDE);
        printf("%s",piscinaDatos->piscinaDeportes[posDeporte]);
        modificarColor(BLANCO);
        printf(".");

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        deporteValidado=validarNombre(respTemp);
        if(deporteValidado)
            deporteValidado=validarRepeticionDeporte(*piscinaDatos,respTemp);
        if(deporteValidado)
            sprintf(piscinaDatos->piscinaDeportes[posDeporte],respTemp);
        else{
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir un nombre de deporte v\240lido. El nombre debe  tener como m\240ximo ");
            modificarColor(VERDE);
            printf("%d",MAX_LONG_CADENA_CARACTERES-1);
            modificarColor(BLANCO);
            printf(" caracteres;");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("no debe comenzar con espacios vac\241os o estar vac\241o y no debe  contener d\241gitos. No debe exis-");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("tir en el sistema.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }
    }while(!deporteValidado);
}

void mostrarDeportes(PD piscinaDatos,COORD posicionMarco){
    int i;

    imprimirMarcoGeneral(4,1,posicionMarco,piscinaDatos.cantidadDeportesAlmacenados+8);
    moverCursor((LONG_ANCHO_MARCO-19)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Reporte de Deportes");
    moverCursor((LONG_ANCHO_MARCO-35)/2+1+posicionMarco.X,posicionMarco.Y+3);
    printf("Deportes Almacenados en el Sistema:");

    for(i=0;i<piscinaDatos.cantidadDeportesAlmacenados;i++){
        moverCursor(posicionMarco.X+4,5+i+posicionMarco.Y);
        printf("%-2d-. %s",i+1, piscinaDatos.piscinaDeportes[i]);
    }

    moverCursor(posicionMarco.X+5,posicionMarco.Y+piscinaDatos.cantidadDeportesAlmacenados+7);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void modificarDeportes(PD *piscinaDatos,COORD posicionMarco){
    int eleccion=-1;
    char eleccionTemp[TAM_CHAR_VAR_VALIDAR];
    bool eleccionValidada=true;
    bool salida=false;

    do{
        imprimirMarcoGeneral(0,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-32)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Men\243 de Modificaci\242n de Deportes");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("0-. Regresar al men\243 de Introducci\242n Manual de Datos.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("1-. Ver Deportes Almacenados en el Sistema.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("2-. Modificar Deporte.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("3-. Eliminar Deporte.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
        printf("4-. Agregar Deporte || Espacio Disponible: ");
        if(CANT_MAX_DEPORTES-piscinaDatos->cantidadDeportesAlmacenados==0)
            modificarColor(ROJO);
        else
            modificarColor(VERDE);
        printf("%d",CANT_MAX_DEPORTES-piscinaDatos->cantidadDeportesAlmacenados);
        modificarColor(BLANCO);

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(eleccionTemp,sizeof(eleccionTemp),stdin);

        eleccionValidada=validarNumeroCorrecto(eleccionTemp,4,0);
        if(eleccionValidada)
            eleccion=atoi(eleccionTemp);
        else
            eleccion=-1;
        switch(eleccion){
        case 0:
            salida=true;
            break;
        case 1:
            mostrarDeportes(*piscinaDatos,posicionMarco);
            break;
        case 2:
            modificarDeporte(piscinaDatos,posicionMarco);
            comunicarOperacionExito(posicionMarco);
            break;
        case 3:
            if(piscinaDatos->cantidadDeportesAlmacenados==1)
                comunicarMinimoDeportesAlcanzadoError(posicionMarco);
            else{
                eliminarDeporte(piscinaDatos,posicionMarco);
                comunicarOperacionExito(posicionMarco);
            }
            break;
        case 4:
            if(piscinaDatos->cantidadDeportesAlmacenados==CANT_MAX_DEPORTES)
                comunicarMaximoDeportesAlcanzadoError(posicionMarco);
            else{
                agregarDeporte(piscinaDatos,posicionMarco);
                comunicarOperacionExito(posicionMarco);
            }
            break;
        default:
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 0 y 4. En dependencia  de su selecci\242n, el  programa");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que le  corresponde  el n\243mero  introducido. Tome  como  gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de modificaci\242n de deportes.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
            break;
        }

    }while(!salida);
}

bool pedirNombreYSexo(char nombre[],char *sexo,int anyo,int numeroParticipante,int contadorComandoAleatorio,PD piscinaDatos,COORD posicionMarco){
    bool comandoAleatorizar=false;
    char respTemp[MAX_LONG_CADENA_CARACTERES+1];
    bool entradaValidada=true;

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-29)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Preguntar Nombre Participante");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca el nombre del participante ");
        modificarColor(VERDE);
        printf("%d",numeroParticipante);
        modificarColor(BLANCO);
        printf(" del a%co ",164);
        modificarColor(VERDE);
        printf("%d",anyo);
        modificarColor(BLANCO);
        printf(".");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("Nota:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("Puede  aleatorizar  los  datos  restantes  de  este  participante  introduciendo  el  comando");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("\"");
        modificarColor(VERDE);
        printf("\\aleatorio");
        modificarColor(BLANCO);
        if(contadorComandoAleatorio==-1)
            printf("\".");
        else{
            printf("\". Tambi\202n puede aleatorizar los datos de los participantes restantes introducien-");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
            printf("do ");
            modificarColor(VERDE);
            printf("3");
            modificarColor(BLANCO);
            printf(" veces seguidas dicho comando.");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+9);
            printf("Ha introducido el comando \"");
            modificarColor(VERDE);
            printf("\\aleatorio");
            modificarColor(BLANCO);
            printf("\" ");
            modificarColor(VERDE);
            printf("%d",contadorComandoAleatorio);
            modificarColor(BLANCO);
            printf(" veces seguidas.");
        }

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        comandoAleatorizar=validarComandoAleatorio(respTemp);
        if(comandoAleatorizar){
            entradaValidada=true;
            *sexo=aleatorizarNombre(piscinaDatos,nombre);
        }
        else{
            entradaValidada=validarNombre(respTemp);
            if(entradaValidada){
                sprintf(nombre,respTemp);

                //Pedir Sexo de Participante
                do{
                    imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
                    moverCursor((LONG_ANCHO_MARCO-27)/2+1+posicionMarco.X,posicionMarco.Y+1);
                    printf("Preguntar Sexo Participante");
                    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
                    printf("Seleccione el sexo del participante ");
                    modificarColor(VERDE);
                    printf("%d",numeroParticipante);
                    modificarColor(BLANCO);
                    printf(" introduciendo la opci\242n listada correspondiente:");
                    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                    printf("1-. Femenino  (");
                    modificarColor(ROSADO);
                    printf("F");
                    modificarColor(BLANCO);
                    printf(").");
                    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                    printf("2-. Masculino (");
                    modificarColor(AZUL);
                    printf("M");
                    modificarColor(BLANCO);
                    printf(").");

                    moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
                    modificarColor(REINICIAR_COLOR);
                    fflush(stdin);
                    fgets(respTemp,sizeof(respTemp),stdin);

                    entradaValidada=validarNumeroCorrecto(respTemp,2,1);
                    if(entradaValidada){
                        if(atoi(respTemp)==1)
                            *sexo='F';
                        else
                            *sexo='M';
                    }
                    else{
                        imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                        printf("Debe introducir  un n\243mero entero  entre 1 y 2. En dependencia  de su selecci\242n, el  programa");
                        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                        printf("ejecutar\240  la acci\242n  que le  corresponde  el n\243mero  introducido. Tome  como  gu\241a  la lista");
                        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                        printf("otorgada en el men\243 de Preguntar Sexo Participante.");
                        moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                        modificarColor(REINICIAR_COLOR);
                        system("pause");
                    }
                }while(!entradaValidada);
            }
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir  un nombre o  comando v\240lido. El nombre debe  tener como m\240ximo ");
                modificarColor(VERDE);
                printf("%d",MAX_LONG_CADENA_CARACTERES-1);
                modificarColor(BLANCO);
                printf(" caracteres;");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("no debe comenzar con espacios vac\241os o estar vac\241o y no debe contener d\241gitos.");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }
    }while(!entradaValidada);

    return comandoAleatorizar;
}

void pedirDeporte(char deporte[],PD piscinaDatos,int anyo,int numeroParticipante,COORD posicionMarco){
    char respTemp[TAM_CHAR_VAR_COMANDO];
    int seleccion,i;
    bool comandoAleatorizar=false;
    bool entradaValidada=true;

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,piscinaDatos.cantidadDeportesAlmacenados+14);
        moverCursor((LONG_ANCHO_MARCO-17)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Preguntar Deporte");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Seleccione uno de  los deportes  disponibles en la  base de datos, marcando la opci\242n listada");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("correspondiente, de manera  que se corresponda al deporte practicado por el participante ");
        modificarColor(VERDE);
        printf("%d",numeroParticipante);
        modificarColor(BLANCO);
        printf(" en");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("los Juegos Intera%cos del a%co ",164,164);
        modificarColor(VERDE);
        printf("%d",anyo);
        modificarColor(BLANCO);
        printf(".");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("Nota:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
        printf("Puede aleatorizar el deporte introduciendo el comando \"");
        modificarColor(VERDE);
        printf("\\aleatorio");
        modificarColor(BLANCO);
        printf("\".");

        for(i=0;i<piscinaDatos.cantidadDeportesAlmacenados;i++){
            moverCursor(posicionMarco.X+4,10+i+posicionMarco.Y);
            printf("%-2d -> %s",i+1, piscinaDatos.piscinaDeportes[i]);
        }

        moverCursor(posicionMarco.X+5,posicionMarco.Y+13+piscinaDatos.cantidadDeportesAlmacenados);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        comandoAleatorizar=validarComandoAleatorio(respTemp);
        if(comandoAleatorizar){
            entradaValidada=true;
            aleatorizarDeporte(piscinaDatos,deporte);
        }
        else{
            entradaValidada=validarNumeroCorrecto(respTemp,piscinaDatos.cantidadDeportesAlmacenados,1);
            if(entradaValidada){
                seleccion=atoi(respTemp);
                sprintf(deporte,piscinaDatos.piscinaDeportes[seleccion-1]);
            }
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir  un n\243mero entero  entre 1 y %d. En  dependencia de su  selecci\242n, el programa",piscinaDatos.cantidadDeportesAlmacenados);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("ejecutar\240  la acci\242n  que  le corresponde  el  n\243mero  introducido. Tome  como gu\241a  la lista");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                printf("otorgada en el men\243 de preguntar deporte.");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }
    }while(!entradaValidada);
}

int pedirCantidadMedallas(int cantidadParticipantes,int anyo,COORD posicionMarco){
    int cantidadMedallas;
    char respTemp[TAM_CHAR_VAR_COMANDO];
    bool entradaValidada=true;
    bool comandoAleatorizar;

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-30)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Preguntar Cantidad de Medallas");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca la  cantidad de  medallas  ganadas  en  los Juegos  Intera%cos  de  la Facultad  de",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("Inform\240tica del a%co ",164);
        modificarColor(VERDE);
        printf("%d",anyo);
        modificarColor(BLANCO);
        printf(".");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("Nota:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("Puede aleatorizar la cantidad de medallas de este  a%co introduciendo el comando \"",164);
        modificarColor(VERDE);
        printf("\\aleatorio");
        modificarColor(BLANCO);
        printf("\".");

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        comandoAleatorizar=validarComandoAleatorio(respTemp);
        if(comandoAleatorizar){
            entradaValidada=true;
            cantidadMedallas=aleatorizarCantidadMedallas(cantidadParticipantes);
        }
        else{
            entradaValidada=validarNumeroCorrecto(respTemp,cantidadParticipantes,0);
            if(entradaValidada)
                cantidadMedallas=atoi(respTemp);
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir un comando o una cantidad v\240lida de medallas, entre ");
                modificarColor(VERDE);
                printf("0");
                modificarColor(BLANCO);
                printf(" y ");
                modificarColor(VERDE);
                printf("%d",cantidadParticipantes);
                modificarColor(BLANCO);
                printf(", que es la cantidad");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("de participantes del a%co ",164);
                modificarColor(VERDE);
                printf("%d",anyo);
                modificarColor(BLANCO);
                printf(".");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }

    }while(!entradaValidada);

    return cantidadMedallas;
}

bool pedirDatosRestantes(DatosAnyo *datosAnyo,PD piscinaDatos,COORD posicionMarco,int contadorComandoAleatorioGlobal){
    bool comandoAleatorizarGlobal=false;
    bool entradaValidada=true;
    char respTemp[TAM_CHAR_VAR_COMANDO];
    int cantidadParticipantes;

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-35)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Preguntar Cantidad de Participantes");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca la cantidad de participantes de los Juegos Intera%cos de la Facultad de Inform\240tica",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("del a%co ",164);
        modificarColor(VERDE);
        printf("%d",datosAnyo->numeroAnyo);
        printf(".");
        modificarColor(BLANCO);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("Nota:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("Puede aleatorizar  los  datos restantes de este  a%co  introduciendo  el comando \"",164);
        modificarColor(VERDE);
        printf("\\aleatorio");
        modificarColor(BLANCO);
        printf("\".");

        if(contadorComandoAleatorioGlobal!=-1){
            moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
            printf("Tambi\202n  puede aleatorizar  los datos de los  a%cos restantes  introduciendo ",164);
            modificarColor(VERDE);
            printf("3");
            modificarColor(BLANCO);
            printf(" veces  seguidas");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+9);
            printf("dicho comando.");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+10);
            printf("Ha introducido el comando \"");
            modificarColor(VERDE);
            printf("\\aleatorio");
            modificarColor(BLANCO);
            printf("\" ");
            modificarColor(VERDE);
            printf("%d",contadorComandoAleatorioGlobal);
            modificarColor(BLANCO);
            printf(" veces seguidas.");
        }

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        comandoAleatorizarGlobal=validarComandoAleatorio(respTemp);
        if(comandoAleatorizarGlobal){
            entradaValidada=true;
            datosAnyo->cantParticipantes=aleatorizarCantidadParticipantes();
            datosAnyo->cantidadMedallas=aleatorizarCantidadMedallas(datosAnyo->cantParticipantes);
            rellenarDatosPersonales(piscinaDatos,datosAnyo,0);
        }
        else{
            entradaValidada=validarNumeroCorrecto(respTemp,CANT_MAX_PARTICIPANTES,0);
            if(entradaValidada){
                cantidadParticipantes=atoi(respTemp);
                datosAnyo->cantParticipantes=cantidadParticipantes;
                if(cantidadParticipantes!=0){
                    int comandoAleatorizar=0;
                    int posicion;
                    bool comandoAleatorio;

                    datosAnyo->cantidadMedallas=pedirCantidadMedallas(datosAnyo->cantParticipantes,datosAnyo->numeroAnyo,posicionMarco);

                    for(posicion=0;posicion<cantidadParticipantes;posicion++){
                        if(comandoAleatorizar==3){
                            rellenarDatosPersonales(piscinaDatos,datosAnyo,posicion);
                        }
                        else{
                            comandoAleatorio=false;
                            comandoAleatorio=pedirNombreYSexo(datosAnyo->participantesAnyo[posicion].nombre,&datosAnyo->participantesAnyo[posicion].sexo,datosAnyo->numeroAnyo,posicion+1,comandoAleatorizar,piscinaDatos,posicionMarco);

                            if(comandoAleatorio){
                                aleatorizarDeporte(piscinaDatos,datosAnyo->participantesAnyo[posicion].deporte);
                                comandoAleatorizar++;
                            }
                            else{
                                pedirDeporte(datosAnyo->participantesAnyo[posicion].deporte,piscinaDatos,datosAnyo->numeroAnyo,posicion+1,posicionMarco);
                                comandoAleatorizar=0;
                            }
                        }
                    }
                }
            }
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir un comando o una cantidad v\240lida de participantes, entre ");
                modificarColor(VERDE);
                printf("0");
                modificarColor(BLANCO);
                printf(" y ");
                modificarColor(VERDE);
                printf("%d",CANT_MAX_PARTICIPANTES);
                modificarColor(BLANCO);
                printf(".");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }

    }while(!entradaValidada);

    return comandoAleatorizarGlobal;
}

bool pedirNombreFeu(DatosAnyo *datosAnyo,PD piscinaDatos,COORD posicionMarco,int contadorComandoAleatorio){
    bool comandoAleatorizar=false;
    bool entradaValidada=true;
    char respTemp[MAX_LONG_CADENA_CARACTERES+1];

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-42)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Preguntar Nombre del Responsable de la FEU");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Introduzca el  nombre del responsable  de la FEU en  los Juegos Intera%cos  de la Facultad  de",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("Inform\240tica del a%co ",164);
        modificarColor(VERDE);
        printf("%d",datosAnyo->numeroAnyo);
        printf(".");
        modificarColor(BLANCO);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("Nota:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("Puede aleatorizar el nombre introduciendo  el comando \"");
        modificarColor(VERDE);
        printf("\\aleatorio");
        modificarColor(BLANCO);
        if(contadorComandoAleatorio==-1)
            printf("\".");
        else{
            printf("\". Tambi\202n puede aleatorizar");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
            printf("los nombres restantes introduciendo ");
            modificarColor(VERDE);
            printf("3");
            modificarColor(BLANCO);
            printf(" veces seguidas dicho comando.");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+9);
            printf("Ha introducido el comando \"");
            modificarColor(VERDE);
            printf("\\aleatorio");
            modificarColor(BLANCO);
            printf("\" ");
            modificarColor(VERDE);
            printf("%d",contadorComandoAleatorio);
            modificarColor(BLANCO);
            printf(" veces seguidas.");
        }

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(respTemp,sizeof(respTemp),stdin);

        comandoAleatorizar=validarComandoAleatorio(respTemp);
        if(comandoAleatorizar){
            entradaValidada=true;
            aleatorizarNombre(piscinaDatos,datosAnyo->nombreResponsable);
        }
        else{
            entradaValidada=validarNombre(respTemp);
            if(entradaValidada)
                sprintf(datosAnyo->nombreResponsable,respTemp);
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir  un nombre o comando v\240lido. El nombre debe  tener como m\240ximo ");
                modificarColor(VERDE);
                printf("%d",MAX_LONG_CADENA_CARACTERES-1);
                modificarColor(BLANCO);
                printf(" caracteres;");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("no debe comenzar con espacios vac\241os o estar vac\241o y no debe contener d\241gitos.");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                printf(" ");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }

    }while(!entradaValidada);

    return comandoAleatorizar;
}

void introducirDesdeCero(DatosAnyo datosAnyo[],PD piscinaDatos,int *cantidadAnyos,COORD posicionMarco){
    DatosAnyo datosTemp[CANTIDAD_ANYOS_MAX];
    char respTemp[TAM_CHAR_VAR_VALIDAR];
    bool numeroValidado;
    bool entradaValidada;
    bool salida;
    bool comandoAleatorio=false;
    int comandoAleatorizar=0;
    int i;

    srand(time(NULL));

    //Informacion General
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor((LONG_ANCHO_MARCO-32)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Introducci\242n de Datos desde Cero");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("El asistente le informar\240 en cada momento los datos necesarios y las selecciones disponibles.");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("Existir\240n  ocasiones en  que si lo desea, podr\240 generar  autom\240ticamente  parte de  los datos");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
    printf("restantes por introducir. Para ello introduzca el comando \"");
    modificarColor(VERDE);
    printf("\\aleatorio");
    modificarColor(BLANCO);
    printf("\".");
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");

    //Preguntar el periodo de tiempo
    do{
        do{
            imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor((LONG_ANCHO_MARCO-23)/2+1+posicionMarco.X,posicionMarco.Y+1);
            printf("Introducci\242n A%co Inicio",164);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
            printf("Introduzca el a%co de inicio de  los datos a introducir en el sistema. El a%co m\241nimo es ",164,164);
            modificarColor(VERDE);
            printf("%d",ANYO_FUNDACION_FAC_INF);
            modificarColor(BLANCO);
            printf(" y");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("el a%co m\240ximo es ",164);
            modificarColor(VERDE);
            printf("%d",determinarAnyoActual());
            modificarColor(BLANCO);
            printf(".");

            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            fflush(stdin);
            fgets(respTemp,sizeof(respTemp),stdin);

            numeroValidado=validarNumeroCorrecto(respTemp,determinarAnyoActual(),ANYO_FUNDACION_FAC_INF);
            if(numeroValidado)
                *cantidadAnyos=determinarAnyoActual()-atoi(respTemp)+1;
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir un a%co v\240lido, entre ",164);
                modificarColor(VERDE);
                printf("%d",ANYO_FUNDACION_FAC_INF);
                modificarColor(BLANCO);
                printf(" y ");
                modificarColor(VERDE);
                printf("%d",determinarAnyoActual());
                modificarColor(BLANCO);
                printf(".");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }

        }while(!numeroValidado);

        do{
            imprimirMarcoGeneral(1,1,posicionMarco,LONG_ALTO_MARCO);

            moverCursor((LONG_ANCHO_MARCO-45)/2+1+posicionMarco.X,posicionMarco.Y+1);
            printf("Ratificaci\242n del Periodo de Datos del Sistema");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
            printf("%cQuiere tomar como periodo de tiempo del sistema de datos a ",-88);
            modificarColor(VERDE);
            printf("%d",determinarAnyoActual()-*cantidadAnyos+1);
            modificarColor(BLANCO);
            printf("-");
            modificarColor(VERDE);
            printf("%d",determinarAnyoActual());
            modificarColor(BLANCO);
            printf("?");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Y/y -> Si quiere mantener dicho periodo de tiempo.");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("N/n -> Si desea volver a introducir un a%co de inicio.",164);

            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            fflush(stdin);
            fgets(respTemp,sizeof(respTemp),stdin);

            entradaValidada=validarYN(respTemp);
            if(entradaValidada){
                if(respTemp[0]=='Y'||respTemp[0]=='y'){
                    rellenarNumerosAnyos(datosTemp,*cantidadAnyos);
                    salida=true;
                }
                else
                    salida=false;
            }
            else{
                imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

                moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
                printf("Debe introducir un caracter: Y/y o N/n. En dependencia de su selecci\242n, el programa ejecutar\240");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
                printf("la acci\242n que le  corresponde el caracter introducido. Tome como gu\241a la lista otorgada en el");
                moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
                printf("men\243 de ratificaci\242n del periodo de datos del sistema.");
                moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
                modificarColor(REINICIAR_COLOR);
                system("pause");
            }
        }while(!entradaValidada);
    }while(!salida);

    //Preguntar nombre de los responsables de la FEU
    comandoAleatorizar=0;
    comandoAleatorio=false;
    for(i=0;i<*cantidadAnyos;i++){
        if(comandoAleatorizar==3)
            aleatorizarNombre(piscinaDatos,datosTemp[i].nombreResponsable);
        else{
            comandoAleatorio=false;
            comandoAleatorio=pedirNombreFeu(&datosTemp[i],piscinaDatos,posicionMarco,comandoAleatorizar);

            if(comandoAleatorio)
                comandoAleatorizar++;
            else
                comandoAleatorizar=0;
        }
    }

    //Preguntar datos restantes
    comandoAleatorizar=0;
    comandoAleatorio=false;
    for(i=0;i<*cantidadAnyos;i++){
        if(comandoAleatorizar==3){
            datosTemp[i].cantParticipantes=aleatorizarCantidadParticipantes();
            datosTemp[i].cantidadMedallas=aleatorizarCantidadMedallas(datosTemp[i].cantParticipantes);
            rellenarDatosPersonales(piscinaDatos,&datosTemp[i],0);
        }
        else{
            comandoAleatorio=false;
            comandoAleatorio=pedirDatosRestantes(&datosTemp[i],piscinaDatos,posicionMarco,comandoAleatorizar);

            if(comandoAleatorio)
                comandoAleatorizar++;
            else
                comandoAleatorizar=0;
        }
    }

    for(i=0;i<*cantidadAnyos;i++)
        datosAnyo[i]=datosTemp[i];
}

void comunicarNoParticipantesError(int anyo,COORD posicionMarco){
    imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("En el a%co seleccionado <",164);
    modificarColor(VERDE);
    printf("%d",anyo);
    modificarColor(BLANCO);
    printf("> no hubo participantes, por lo que no puede realizarse la opera-");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
    printf("ci\242n seleccionada.");
    moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}
int preguntarParticipante(DatosAnyo datosAnyo,COORD posicionMarco){
    int i,posParticipante=0;
    char posParticipanteTemp[TAM_CHAR_VAR_VALIDAR];
    bool numeroValidado=true;

    do{
        imprimirMarcoGeneral(1,1,posicionMarco,datosAnyo.cantParticipantes+8);
        moverCursor((LONG_ANCHO_MARCO-20)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Escoger Participante");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Seleccione uno de los participantes disponibles en la  base de datos, marcando la opci\242n lis-");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("tada correspondiente:");

        for(i=0;i<datosAnyo.cantParticipantes;i++){
            moverCursor(posicionMarco.X+4,5+i+posicionMarco.Y);
            printf("%-2d -> %s",i+1,datosAnyo.participantesAnyo[i].nombre);
        }

        moverCursor(posicionMarco.X+5,datosAnyo.cantParticipantes+7+posicionMarco.Y);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(posParticipanteTemp,sizeof(posParticipanteTemp),stdin);

        numeroValidado=validarNumeroCorrecto(posParticipanteTemp,datosAnyo.cantParticipantes,1);
        if(numeroValidado)
            posParticipante=atoi(posParticipanteTemp);
        else{
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 1 y %d. En dependencia de  su selecci\242n, el programa",datosAnyo.cantParticipantes);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que  le  corresponde  el n\243mero  introducido. Tome  como gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de escoger participante.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
        }

    }while(!numeroValidado);
    return posParticipante-1;
}

void modificarDatos(DatosAnyo datosAnyo[],PD piscinaDatos,int cantidadAnyos,COORD posicionMarco){
    int temp1,temp2,eleccion=-1;
    char eleccionTemp[TAM_CHAR_VAR_VALIDAR];
    bool eleccionValidada=true;
    bool salida=false;

    do{
        imprimirMarcoGeneral(0,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-42)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Men\243 de Modificaci\242n de Datos del Sistema");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("0-. Regresar al men\243 de Introducci\242n Manual de Datos.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("1-. Ver Datos Almacenados en el Sistema.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("2-. Modificar Represante de la FEU de un a%co espec\241fico.",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("3-. Modificar Cantidad de Participantes de un a%co espec\241fico (Elimina los datos de los parti-",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+8);
        printf("cipantes de dicho a%co, por lo que tendr\240 que introducirlos).",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+9);
        printf("4-. Modificar Cantidad de Medallas de un a%co espec\241fico.",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+10);
        printf("5-. Modificar Nombre y Sexo de un participante espec\241fico de un a%co espec\241fico.",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+11);
        printf("6-. Modificar Deporte practicado por un participante espec\241fico de un a%co espec\241fico.",164);

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(eleccionTemp,sizeof(eleccionTemp),stdin);

        eleccionValidada=validarNumeroCorrecto(eleccionTemp,6,0);
        if(eleccionValidada)
            eleccion=atoi(eleccionTemp);
        else
            eleccion=-1;
        switch(eleccion){
        case 0:
            salida=true;
            break;
        case 1:
            mostrarReporteAnual(datosAnyo,cantidadAnyos,posicionMarco);
            break;
        case 2:
            pedirNombreFeu(&datosAnyo[preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco)],piscinaDatos,posicionMarco,-1);
            comunicarOperacionExito(posicionMarco);
            break;
        case 3:
            pedirDatosRestantes(&datosAnyo[preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco)],piscinaDatos,posicionMarco,-1);
            comunicarOperacionExito(posicionMarco);
            break;
        case 4:
            temp1=preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco);
            datosAnyo[temp1].cantidadMedallas=pedirCantidadMedallas(datosAnyo[temp1].cantParticipantes,datosAnyo[temp1].numeroAnyo,posicionMarco);
            comunicarOperacionExito(posicionMarco);
            break;
        case 5:
            temp1=preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco);
            if(datosAnyo[temp1].cantParticipantes==0)
                comunicarNoParticipantesError(datosAnyo[temp1].numeroAnyo,posicionMarco);
            else{
                temp2=preguntarParticipante(datosAnyo[temp1],posicionMarco);
                pedirNombreYSexo(datosAnyo[temp1].participantesAnyo[temp2].nombre,&datosAnyo[temp1].participantesAnyo[temp2].sexo,datosAnyo[temp1].numeroAnyo,temp2+1,-1,piscinaDatos,posicionMarco);
                comunicarOperacionExito(posicionMarco);
            }
            break;
        case 6:
            temp1=preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco);
            if(datosAnyo[temp1].cantParticipantes==0)
                comunicarNoParticipantesError(datosAnyo[temp1].numeroAnyo,posicionMarco);
            else{
                temp2=preguntarParticipante(datosAnyo[temp1],posicionMarco);
                pedirDeporte(datosAnyo[temp1].participantesAnyo[temp2].deporte,piscinaDatos,datosAnyo[temp1].numeroAnyo,temp2+1,posicionMarco);
                comunicarOperacionExito(posicionMarco);
            }
            break;
        default:
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 0 y 6. En dependencia  de su selecci\242n, el  programa");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que le  corresponde  el n\243mero  introducido. Tome  como  gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de modificaci\242n de datos del sistema.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
            break;
        }
    }while(!salida);
}

void comunicarDatosNoInicializadosError(COORD posicionMarco){
    imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);

    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("No existen datos en el sistema. Debe introducirlos  manualmente o generarlos de forma autom\240-");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
    printf("tica.");
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void introducirDatosUsuario(DatosAnyo datosAnyo[], PD *piscinaDatos, int *cantidadAnyos, bool *datosExistentes, COORD posicionMarco){
    int eleccion;
    char eleccionTemp[TAM_CHAR_VAR_VALIDAR];
    bool salida=false;
    bool respTemp=true;

    //Asistente Bienvenida
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);
    moverCursor((LONG_ANCHO_MARCO-41)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Asistente de Introducci\242n Manual de Datos");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("Bienvenido/a  al asistente  de Introducci\242n  Manual  de Datos  del Sistema  de Deportes de la");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("FEU-CUJAE de la Facultad  de Inform\240tica. A continuaci\242n  el asistente  le guiar\240 para intro-");
    moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
    printf("ducir de forma correcta los datos.");
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");

    //Menú de Inicialización Automática
    do{
        imprimirMarcoGeneral(0,1,posicionMarco,LONG_ALTO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-36)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("Men\243 de Introducci\242n Manual de Datos");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("0-. Regresar al men\243 principal.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("1-. Introducci\242n Manual desde Cero.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("2-. Modificar datos existentes en el sistema.");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("3-. Modificar deportes existentes.");

        moverCursor(posicionMarco.X+5,posicionMarco.Y-1+LONG_ALTO_MARCO);
        modificarColor(REINICIAR_COLOR);
        fflush(stdin);
        fgets(eleccionTemp,sizeof(eleccionTemp),stdin);

        bool numeroValidado=validarNumeroCorrecto(eleccionTemp,3,0);
        if(numeroValidado)
            eleccion=atoi(eleccionTemp);
        else
            eleccion=-1;

        switch (eleccion) {
        case 0:
            salida=true;
            break;
        case 1:
            introducirDesdeCero(datosAnyo,*piscinaDatos,cantidadAnyos,posicionMarco);
            *datosExistentes=true;
            comunicarOperacionExito(posicionMarco);
            break;
        case 2:
            if(!*datosExistentes)
                comunicarDatosNoInicializadosError(posicionMarco);
            else
                modificarDatos(datosAnyo,*piscinaDatos,*cantidadAnyos,posicionMarco);
            break;
        case 3:
            if(*datosExistentes)
                respTemp=preguntarDatosExistentesAdv(posicionMarco,2);
            if(respTemp){
                modificarDeportes(piscinaDatos,posicionMarco);
                *datosExistentes=false;
            }
            break;
        default:
            imprimirMarcoGeneral(2,1,posicionMarco,LONG_ALTO_MARCO);
            moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
            printf("Debe introducir  un n\243mero entero  entre 0 y 3. En dependencia  de su selecci\242n, el  programa");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
            printf("ejecutar\240  la acci\242n  que le  corresponde  el n\243mero  introducido. Tome  como  gu\241a  la lista");
            moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
            printf("otorgada en el men\243 de introducci\242n manual de datos.");
            moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
            modificarColor(REINICIAR_COLOR);
            system("pause");
            break;
        }
    }while(!salida);
}

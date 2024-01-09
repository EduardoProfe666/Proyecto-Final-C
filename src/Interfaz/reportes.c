#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Logica/definiciones.h"
#include "Logica/estructura.h"
#include "Logica/logica.h"
#include "Interfaz/consola.h"
#include "Interfaz/preguntasAlUsuario.h"

void imprimirMarcoExtremosRptAnual(int posicion_Y_Contador, int formatoMarco,COORD posicionMarco){
    //formatoMarco:0->Formato Principio; 1->Formato Final
    int i;

    moverCursor(posicionMarco.X,posicion_Y_Contador+posicionMarco.Y);
    for(i=1;i<=LONG_ANCHO_MARCO+1;i++){
        switch(i) {
        case 1:
            printf("%c", 204);
            break;
        case LONG_ANCHO_MARCO+1:
            printf("%c", 185);
            break;
        case LONG_ANCHO_MARCO/3+2:
            printf("%c", formatoMarco==0 ? 203 : 202);
            break;
        case (LONG_ANCHO_MARCO/3)*2+2:
            printf("%c", formatoMarco==0 ? 203 : 202);
            break;
        default:
            printf("%c", 205);
            break;
        }
    }
}

void imprimirMarcoCuerpoTablaRptAnual(int posicion_Y_Contador,int formatoMarco,COORD posicionMarco){
    //formatoMarco:0->Formato Primero; 1->Formato Relleno

    if(formatoMarco==0){
        moverCursor(LONG_ANCHO_MARCO/3+1+posicionMarco.X,posicion_Y_Contador+posicionMarco.Y);
        printf("%c", 186);
        moverCursor((LONG_ANCHO_MARCO/3)*2+1+posicionMarco.X,posicion_Y_Contador+posicionMarco.Y);
        printf("%c", 186);
    }
    else{
        moverCursor(LONG_ANCHO_MARCO/3+1+posicionMarco.X,posicion_Y_Contador+posicionMarco.Y);
        printf("%c", 206);
        moverCursor((LONG_ANCHO_MARCO/3)*2+1+posicionMarco.X,posicion_Y_Contador+posicionMarco.Y);
        printf("%c", 206);
    }
}

void mostrarPorcentajeAnualMedallasParticipantes(DatosAnyo datosAnyo[], int cantidadAnyos,COORD posicionMarco){
    int i;

    imprimirMarcoGeneral(4,1,posicionMarco,cantidadAnyos+7);

    moverCursor((LONG_ANCHO_MARCO-57)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Reporte anual de porcentaje de medallas seg\243n participantes");

    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("El porcentaje de medallas ganadas seg\243n la cantidad total de participantes en cada a%co fue:",164);

    for(i=0;i<cantidadAnyos;i++){
        moverCursor(posicionMarco.X+4,4+i+posicionMarco.Y);
        float porcentaje = determinarPorcentajeAnualMedallasParticipantes(datosAnyo[i].cantidadMedallas, datosAnyo[i].cantParticipantes);

        if(porcentaje<0){
            modificarColor(ROJO);
            printf("%d -> -------", datosAnyo[i].numeroAnyo);
        }else{
            if(porcentaje==0)
                modificarColor(ROJO);
            else if(porcentaje==100)
                modificarColor(VERDE);
            printf("%d -> %6.2f%%", datosAnyo[i].numeroAnyo,porcentaje);
        }
        modificarColor(BLANCO);
    }

    moverCursor(posicionMarco.X+5,cantidadAnyos+6+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

//Al mostrar los datos en el reporte anual parece que es un ciclo infinito por la demora, pero NO lo es. Esperar que se termine de cargar.
void mostrarReporteAnual(DatosAnyo datosAnyo[],int cantidadAnyos,COORD posicionMarco){
    int anyos,i,k;

    system("cls");
    modificarColor(BLANCO);
    modificarTamanyoBuffer(BUFFER_RPT_X,BUFFER_RPT_Y);

    moverCursor((LONG_ANCHO_MARCO-34)/2+1+posicionMarco.X,posicionMarco.Y);
    printf("Reporte Anual de Datos Almacenados");
    for(anyos=0,k=3;anyos<cantidadAnyos;anyos++,k+=2){
        modificarColor(REINICIAR_COLOR);
        imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO, 0);

        imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
        moverCursor((LONG_ANCHO_MARCO-4)/2+1+posicionMarco.X,posicionMarco.Y+k++);
        modificarColor(AZUL_CLARO);
        printf("%d", datosAnyo[anyos].numeroAnyo);
        modificarColor(REINICIAR_COLOR);
        imprimirUnionCuerpoExtremosMarco(posicionMarco.X,posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO);

        imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
        moverCursor(posicionMarco.X+1,posicionMarco.Y+k++);
        modificarColor(BLANCO);
        printf("Responsable de la FEU-DEPORTES: %s", datosAnyo[anyos].nombreResponsable);
        modificarColor(REINICIAR_COLOR);
        imprimirUnionCuerpoExtremosMarco(posicionMarco.X,posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO);

        imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
        if(datosAnyo[anyos].cantParticipantes==0){  //Caso Extremo
            moverCursor((LONG_ANCHO_MARCO-30)/2+1+posicionMarco.X,posicionMarco.Y+k++);
            modificarColor(ROJO);
            printf("No hubo participantes este a%co",164);
            modificarColor(REINICIAR_COLOR);
        }
        else{
            moverCursor(posicionMarco.X+1,posicionMarco.Y+k++);
            modificarColor(BLANCO);
            printf("Total de medallas ganadas: ");
            if(datosAnyo[anyos].cantidadMedallas==0)
                modificarColor(ROJO);
            else
                modificarColor(VERDE);
            printf("%d", datosAnyo[anyos].cantidadMedallas);
            modificarColor(REINICIAR_COLOR);
            imprimirUnionCuerpoExtremosMarco(posicionMarco.X,posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO);

            imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
            moverCursor((LONG_ANCHO_MARCO-24)/2+1+posicionMarco.X,posicionMarco.Y+k++);
            modificarColor(BLANCO);
            printf("Listado de Participantes");
            modificarColor(REINICIAR_COLOR);
            imprimirMarcoExtremosRptAnual(k++,0,posicionMarco);

            imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
            imprimirMarcoCuerpoTablaRptAnual(k,0,posicionMarco);
            moverCursor((LONG_ANCHO_MARCO/3-6)/2+1+posicionMarco.X,posicionMarco.Y+k);
            modificarColor(BLANCO);
            printf("Nombre");
            moverCursor(((LONG_ANCHO_MARCO/3-2)/2+1)*3+posicionMarco.X,posicionMarco.Y+k);
            printf("Sexo");
            moverCursor(((LONG_ANCHO_MARCO/3-2)/2+1)*5+posicionMarco.X,posicionMarco.Y+k++);
            printf("Deporte");
            modificarColor(REINICIAR_COLOR);

            for(i=0;i<datosAnyo[anyos].cantParticipantes;i++){
                imprimirUnionCuerpoExtremosMarco(posicionMarco.X,posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
                imprimirMarcoCuerpoTablaRptAnual(k++,1,posicionMarco);

                imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
                imprimirMarcoCuerpoTablaRptAnual(k,0,posicionMarco);
                moverCursor(posicionMarco.X+1,posicionMarco.Y+k);
                modificarColor(BLANCO);
                printf("%2d-.%s",i+1, datosAnyo[anyos].participantesAnyo[i].nombre);
                moverCursor((LONG_ANCHO_MARCO/3)+2+posicionMarco.X,posicionMarco.Y+k);
                if(datosAnyo[anyos].participantesAnyo[i].sexo=='M'){
                    printf("Masculino (");
                    modificarColor(AZUL);
                    printf("M");
                    modificarColor(BLANCO);
                    printf(")");
                }
                else{
                    printf("Femenino  (");
                    modificarColor(ROSADO);
                    printf("F");
                    modificarColor(BLANCO);
                    printf(")");
                }
                moverCursor((LONG_ANCHO_MARCO/3)*2+2+posicionMarco.X,posicionMarco.Y+k++);
                printf("%s",datosAnyo[anyos].participantesAnyo[i].deporte);
                modificarColor(REINICIAR_COLOR);
            }

            imprimirMarcoExtremosRptAnual(k++,1,posicionMarco);
            imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k,posicionMarco.X+LONG_ANCHO_MARCO);
            moverCursor(posicionMarco.X+1,posicionMarco.Y+k++);
            modificarColor(BLANCO);
            printf("Total de participantes: ");
            modificarColor(VERDE);
            printf("%d", datosAnyo[anyos].cantParticipantes);
            modificarColor(REINICIAR_COLOR);
        }
        imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO, 1);
    }

    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO, 0);
    moverCursor(posicionMarco.X+1,posicionMarco.Y+k);
    modificarColor(BLANCO);
    printf("Cantidad de a%cos almacenados -> ",164);
    modificarColor(VERDE);
    printf("%d",cantidadAnyos);
    modificarColor(REINICIAR_COLOR);
    imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO);
    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+k++,posicionMarco.X+LONG_ANCHO_MARCO, 1);

    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+(k++)+2,posicionMarco.X+LONG_ANCHO_MARCO, 0);
    imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+(k++)+2,posicionMarco.X+LONG_ANCHO_MARCO);
    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y+(k++)+2,posicionMarco.X+LONG_ANCHO_MARCO, 1);
    moverCursor(posicionMarco.X+1,posicionMarco.Y+k);
    modificarColor(BLANCO);
    printf(">> \a");
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void mostrarAnyosMayoresMujeres(DatosAnyo datosAnyo[], int cantidadAnyos,COORD posicionMarco){
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);

    moverCursor((LONG_ANCHO_MARCO-54)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Total de a%cos con mayor cifra de mujeres participantes", 164);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
    printf("El total  de a%cos  en que la  cifra de  mujeres participantes  en los Juegos  Intera%cos de la",164,164);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
    printf("Facultad de Inform\240tica super\242 a la cantidad de hombres participantes fue de ");
    int anyos = determinarTotalAnyoMayorMujeres(datosAnyo,cantidadAnyos);
    if(anyos == 0)
        modificarColor(ROJO);
    else
        modificarColor(VERDE);
    printf("%d", anyos);
    modificarColor(BLANCO);
    printf(" a%cos.", 164);
    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void mostrarAnyoMayorMedallas(DatosAnyo datosAnyo[],int cantidadAnyos,COORD posicionMarco){
    imprimirMarcoGeneral(4,1,posicionMarco,LONG_ALTO_MARCO);

    moverCursor((LONG_ANCHO_MARCO-40)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("A%co con mayor n\243mero de medallas ganadas", 164);
    moverCursor(posicionMarco.X+4,posicionMarco.Y+3);

    int anyoMayorMedallas=determinarAnyoMayorMedallas(datosAnyo,cantidadAnyos);
    if(anyoMayorMedallas==-1){
        printf("La facultad de Inform\240tica ");
        modificarColor(ROJO);
        printf("no");
        modificarColor(BLANCO);
        printf(" gan\242 medallas ning\243n a%co en los Juegos Intera%cos.",164,164);
    }
    else{
        printf("El a%co que la facultad de Inform\240tica gan\242 m\240s medallas en los Juegos Intera%cos fue en ",164,164);
        modificarColor(VERDE);
        printf("%d", anyoMayorMedallas);
        modificarColor(BLANCO);
        printf(".");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+5);
        printf("NOTA:");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+6);
        printf("En caso de repetirse los a%cos con iguales n\243meros de medallas mayores se escoge  el \243ltimo de",164);
        moverCursor(posicionMarco.X+4,posicionMarco.Y+7);
        printf("estos a%cos como el de mayor n\243mero de medallas.",164);
    }

    moverCursor(posicionMarco.X+5,LONG_ALTO_MARCO-1+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");
}

void mostrarReporteParticipantesDadoAnyoDeporte(DatosAnyo datosAnyo[],PD baseDeDatos,int cantidadAnyos,COORD posicionMarco){
    int i, k;
    int anyoSeleccionadoPos = preguntarAnyo(datosAnyo,cantidadAnyos,posicionMarco);
    int deporteSeleccionadoPos = preguntarDeporte(baseDeDatos,posicionMarco);
    int cantidadParticipantesSeleccionados=0;


    system("cls");
    modificarTamanyoBuffer(BUFFER_INTPR_X,BUFFER_INTPR_Y);

    modificarColor(BLANCO);
    moverCursor((LONG_ANCHO_MARCO-58)/2+1+posicionMarco.X,posicionMarco.Y+1);
    printf("Reporte de participantes dado un a%co y deporte espec\241fico",164);

    for(i=0,k=0;i<datosAnyo[anyoSeleccionadoPos].cantParticipantes;i++,k++){
        moverCursor(posicionMarco.X+4,5+k+posicionMarco.Y);
        if(strcmp(datosAnyo[anyoSeleccionadoPos].participantesAnyo[i].deporte, baseDeDatos.piscinaDeportes[deporteSeleccionadoPos])==0){
            printf("%d-. %s",k+1,datosAnyo[anyoSeleccionadoPos].participantesAnyo[i].nombre);
            cantidadParticipantesSeleccionados++;
        }
        else
            k--;
    }
    if(cantidadParticipantesSeleccionados==0){ //Caso Extremo
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("En los Juegos  Intera%cos de la Facultad  de Inform\240tica del a%co",164,164);
        modificarColor(VERDE);
        printf(" %d ", datosAnyo[anyoSeleccionadoPos].numeroAnyo);
        modificarColor(ROJO);
        printf("no ");
        modificarColor(BLANCO);
        printf("hubo participantes en");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("el deporte");
        modificarColor(VERDE);
        printf(" %s", baseDeDatos.piscinaDeportes[deporteSeleccionadoPos]);
        modificarColor(BLANCO);
        printf(".");
    }
    else{
        moverCursor(posicionMarco.X+4,posicionMarco.Y+3);
        printf("Los participantes  de los Juegos  Intera%cos de la  Facultad de Inform\240tica del a%co",164 , 164);
        modificarColor(VERDE);
        printf(" %d ",datosAnyo[anyoSeleccionadoPos].numeroAnyo);
        modificarColor(BLANCO);
        printf("en el");
        moverCursor(posicionMarco.X+4,posicionMarco.Y+4);
        printf("deporte");
        modificarColor(VERDE);
        printf(" %s ", baseDeDatos.piscinaDeportes[deporteSeleccionadoPos]);
        modificarColor(BLANCO);
        printf("fueron:");
    }

    imprimirMarcoGeneral(4,0,posicionMarco,cantidadParticipantesSeleccionados+8);

    moverCursor(posicionMarco.X+5,cantidadParticipantesSeleccionados+7+posicionMarco.Y);
    modificarColor(REINICIAR_COLOR);
    system("pause");

}


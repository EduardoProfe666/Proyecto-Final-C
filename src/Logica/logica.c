#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Logica/definiciones.h"
#include "Logica/estructura.h"
#include "Interfaz/preguntasAlUsuario.h"

int determinarAnyoActual(){
    time_t actualidad;
    time(&actualidad);
    struct tm *tiempo = localtime(&actualidad);
    return tiempo -> tm_year+1900;
}

void aleatorizarCantidadAnyos(int *cantidadAnyos){
    *cantidadAnyos=rand()%((determinarAnyoActual()-ANYO_FUNDACION_FAC_INF+2)-CANTIDAD_ANYOS_MIN)+CANTIDAD_ANYOS_MIN; //Para que hayan como mínimo CANTIDAD_ANYOS_MIN años
}

void rellenarNumerosAnyos(DatosAnyo datosAnyo[],int cantidadAnyos){
    int i;
    for(i=0;i<cantidadAnyos;i++)
        datosAnyo[i].numeroAnyo=determinarAnyoActual()-cantidadAnyos+1+i;
}

int aleatorizarCantidadParticipantes(){
    int cantParticipantes=rand()%((CANT_MAX_PARTICIPANTES+1)-CANT_MIN_PARTICIPANTES)+CANT_MIN_PARTICIPANTES; //Para que hayan como mínimo CANT_MIN_PARTICIPANTES participantes
    return cantParticipantes;
}

char aleatorizarNombre(PD piscinaDatos,char nombre[]){
    int k=rand()%CANT_DATOS_PERSONALES_PD;
    sprintf(nombre,piscinaDatos.piscinaNombres[k]);
    strcat(nombre," ");
    strcat(nombre,piscinaDatos.piscinaApellidos[rand()%CANT_DATOS_PERSONALES_PD]);
    return piscinaDatos.piscinaSexo[k];
}

void aleatorizarDeporte(PD piscinaDatos,char deporte[]){
    sprintf(deporte,piscinaDatos.piscinaDeportes[rand()%piscinaDatos.cantidadDeportesAlmacenados]);
}

int aleatorizarCantidadMedallas(int maximaCantidad){
    int cantidadMedallas=rand()%(maximaCantidad+1);  //No pueden haber mas medallas que participantes
    return cantidadMedallas;
}

void rellenarDatosPersonales(PD piscinaDatos,DatosAnyo *datosAnyo,int posicionInicio){
    int i;
    for(i=posicionInicio;i<datosAnyo->cantParticipantes;i++){
        datosAnyo->participantesAnyo[i].sexo=aleatorizarNombre(piscinaDatos,datosAnyo->participantesAnyo[i].nombre);
        aleatorizarDeporte(piscinaDatos,datosAnyo->participantesAnyo[i].deporte);
    }
}

void inicializarDatos(DatosAnyo datosAnyo[], PD piscinaDatos, int *cantidadAnyos){
    int i;

    srand(time(NULL));

    aleatorizarCantidadAnyos(cantidadAnyos);
    rellenarNumerosAnyos(datosAnyo,*cantidadAnyos);

    for(i=0;i<*cantidadAnyos;i++){
        aleatorizarNombre(piscinaDatos,datosAnyo[i].nombreResponsable);
        datosAnyo[i].cantParticipantes=aleatorizarCantidadParticipantes();
        datosAnyo[i].cantidadMedallas =aleatorizarCantidadMedallas(datosAnyo[i].cantParticipantes);
        rellenarDatosPersonales(piscinaDatos,&datosAnyo[i],0);
    }
}

void inicializarBaseDeDatos(PD *baseDeDatoS){ //Se hizo así porque el usuario puede luego agregar o eliminar deportes
    //Piscinas de datos, NO AGREGAR O ELIMINAR SIN HACER COMPENSACIONES, EXCEPTO DEPORTES CON PRECAUCIÓN
    char *piscinaDeNombres[]={
        "Eduardo","Julia","Alberto","Juan","Eva","Hugo","Lucas","Leo","Zoe","Ariadna",
        "Yami","Felipe","Vilma","Marco","Celia","Sonia","Alejandro","Milos","Clara","Pedro",
        "Gerard","India","Victoria","Cristian","Marina","Carlota","Luna","David","Elsa","Isabel",
        "Mario","Paula","Bruno","Karla","Oliverio","Mar\241a","Thiago","Alma","Sergio","Elena",
        "Manuela","Eric","Adriana","Iv\240n","Alejandra","Guillermo","Alicia","Joel","Guadalupe","Ismael"
    };
    //Se relaciona directamente con la de nombres
    char piscinaDeSexo[]={
        'M','F','M','M','F','M','M','M','F','F','F','M','F','M','F','F','M','M','F','M',
        'M','F','F','M','F','F','F','M','F','F','M','F','M','F','M','F','M','F','M','F',
        'F','M','F','M','F','M','F','M','F','M'
    };

    char *piscinaDeApellidos[]={
        "Castro","Martell","Morales","Rivera","Reyes","Romero","Escobar","Cruz","Rivas","Orellana",
        "Aguilar","Alvarado","Zambrano","Torres","Zabala","Vera","Flores","Espinosa","Jaramillo","Mendoza",
        "Ayala","Morillo","Acosta","Rojas","Ortiz","Galeano","Ferreira","Cabrera","Sosa","Franco",
        "Navarro","Ramos","Serrano","Molina","Gil","Blanco","Ortega","Delgado","Rubio","Medina",
        "Iglesias","Castillo","Santos","Guerrero","Lozano","Cano","Herrera","Gallego","Calvo","Vega"
    };

    char *piscinaDeDeportes[]={
        "Ajedrez","Baloncesto","Balonmano","B\202isbol","F\243tbol","Judo","Nataci\242n"
    };

    int i;

    //Inicializacion de Valores
    for(i=0;i<CANT_DATOS_PERSONALES_PD;i++)
        sprintf(baseDeDatoS->piscinaNombres[i],piscinaDeNombres[i]);

    for(i=0;i<CANT_DATOS_PERSONALES_PD;i++)
        baseDeDatoS->piscinaSexo[i]=piscinaDeSexo[i];

    for(i=0;i<CANT_DATOS_PERSONALES_PD;i++)
        sprintf(baseDeDatoS->piscinaApellidos[i],piscinaDeApellidos[i]);

    for(i=0;i<CANT_MAX_DEPORTES && i<(int)sizeof(piscinaDeDeportes)/TAMANYO_PTR_CHAR_ARR;i++)
        sprintf(baseDeDatoS->piscinaDeportes[i],piscinaDeDeportes[i]);

    baseDeDatoS->cantidadDeportesAlmacenados=sizeof(piscinaDeDeportes)/TAMANYO_PTR_CHAR_ARR;
}

int determinarAnyoMayorMedallas(DatosAnyo datosAnyo[],int cantidadAnyos){
    int i;                  //En caso de repetirse los años con iguales números de medallas mayores se escoge
    int anyoMayorMedallas=-1;  //el último de esos años como el de mayor número de medallas
    int cantMedallas=-1;

    for(i=0;i<cantidadAnyos;i++){
        if(datosAnyo[i].cantidadMedallas>=cantMedallas){
            cantMedallas=datosAnyo[i].cantidadMedallas;
            anyoMayorMedallas= cantMedallas!=0 ? datosAnyo[i].numeroAnyo : -1;
        }
    }
    return anyoMayorMedallas;
}

int determinarTotalAnyoMayorMujeres(DatosAnyo datosAnyo[],int cantidadAnyos){
    int i,j;
    int totalAnyosMayorMujeres=0;

    for(i=0;i<cantidadAnyos;i++){
        int totalMujeres=0;
        for(j=0;j<datosAnyo[i].cantParticipantes;j++)
            if(datosAnyo[i].participantesAnyo[j].sexo=='F')
                totalMujeres++;
        if(totalMujeres>datosAnyo[i].cantParticipantes/2)
            totalAnyosMayorMujeres++;
    }

    return totalAnyosMayorMujeres;
}

float determinarPorcentajeAnualMedallasParticipantes(int cantidadMedallas, int cantidadParticipantes){
    float porcentajeAnual;

    porcentajeAnual= cantidadParticipantes>0 ? (float)cantidadMedallas/cantidadParticipantes*100 : -1;

    return porcentajeAnual;
}

void eliminarDeporte(PD *piscinaDatos,COORD posicionMarco){
    int posDeporte=preguntarDeporte(*piscinaDatos,posicionMarco);
    int i;

    for(i=posDeporte;i<piscinaDatos->cantidadDeportesAlmacenados-1;i++)
        strcpy(piscinaDatos->piscinaDeportes[i],piscinaDatos->piscinaDeportes[i+1]);

    piscinaDatos->cantidadDeportesAlmacenados--;
}

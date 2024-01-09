#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Logica/definiciones.h"
#include "Logica/estructura.h"

bool esNumero(char cadenaCaracteres[]){
    bool esNum=true;
    int i;

    for(i=0;i<(int)strlen(cadenaCaracteres)-1;i++){
        if(isdigit(cadenaCaracteres[i])==0)
            esNum=false;
    }

    return esNum;
}

bool validarNumeroCorrecto(char cadenaCaracteres[],int cantMax,int cantMin){
    bool numeroValidado=true;

    if(cadenaCaracteres[0]==0xA)
        numeroValidado=false;

    if(numeroValidado)
        if(!esNumero(cadenaCaracteres))
            numeroValidado=false;

    if(numeroValidado)
        if(cadenaCaracteres[0]=='0'&& cadenaCaracteres[1]!=0xA)
            numeroValidado=false;

    if(numeroValidado)
        if(atoi(cadenaCaracteres)<cantMin||atoi(cadenaCaracteres)>cantMax)
            numeroValidado=false;
    return numeroValidado;
}

bool validarYN(char cadenaCaracteres[]){
    bool y_n_validado=false;

    strupr(cadenaCaracteres);

    if((cadenaCaracteres[0]=='Y' || cadenaCaracteres[0]=='N') && cadenaCaracteres[1]==0xA)
        y_n_validado=true;

    return y_n_validado;
}

bool validarComandoAleatorio(char cadenaCaracteres[]){
    bool comandoAleatorioValidado=false;
    char temp[MAX_LONG_CADENA_CARACTERES];
    char cmdAleatorio[TAM_CHAR_VAR_COMANDO]="\\aleatorio\n";

    strcpy(temp,cadenaCaracteres);

    strlwr(temp);
    if(strcmp(temp,cmdAleatorio)==0)
        comandoAleatorioValidado=true;

    return comandoAleatorioValidado;
}

bool validarComandoOrqui(char cadenaCaracteres[]){
    bool comandoTemaValidado=false;
    char temp[MAX_LONG_CADENA_CARACTERES];
    char cmdOrqui[TAM_CHAR_VAR_COMANDO]="\\orqui\n";

    strcpy(temp,cadenaCaracteres);

    strlwr(temp);
    if(strcmp(temp,cmdOrqui)==0)
        comandoTemaValidado=true;

    return comandoTemaValidado;
}

bool validarNombre(char cadenaCaracteres[]){
    bool nombreValidado=true;
    int i;

    if(cadenaCaracteres[0]==0xA || cadenaCaracteres[(int)strlen(cadenaCaracteres)-1]!=0xA)
        nombreValidado=false;

    if(nombreValidado)
        if(cadenaCaracteres[0]=='\\')
            nombreValidado=false;

    if(nombreValidado)
        if(isspace(cadenaCaracteres[0])!=0)
            nombreValidado=false;

    if(nombreValidado)
        for(i=0;i<(int)strlen(cadenaCaracteres)-1 && nombreValidado;i++)
            if(isdigit(cadenaCaracteres[i])!=0)
                nombreValidado=false;

    strtok(cadenaCaracteres,"\n");

    return nombreValidado;
}

bool validarRepeticionDeporte(PD piscinaDatos,char cadenaIntroducida[]){
    bool noRepetido=true;
    int i;
    char CadenaIntroducidaTemp[MAX_LONG_CADENA_CARACTERES];
    strcpy(CadenaIntroducidaTemp,cadenaIntroducida);
    strlwr(CadenaIntroducidaTemp);

    for(i=0;i<piscinaDatos.cantidadDeportesAlmacenados && noRepetido;i++){
        char DeporteTemp[MAX_LONG_CADENA_CARACTERES];
        strcpy(DeporteTemp,piscinaDatos.piscinaDeportes[i]);
        strlwr(DeporteTemp);

        if(strcmp(DeporteTemp,CadenaIntroducidaTemp)==0)
            noRepetido=false;
    }

    return noRepetido;
}

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Logica/definiciones.h"

void modificarColor(int colorCodigo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorCodigo);
}

void prepararConsola(){
    HWND consola = GetConsoleWindow();
    int anchoPantalla, altoPantalla;
    anchoPantalla = GetSystemMetrics(SM_CXSCREEN);
    altoPantalla = GetSystemMetrics(SM_CYSCREEN);
    MoveWindow(consola, (anchoPantalla-ANCHO_VENTANA_CONSOLA)/2, (altoPantalla-ALTO_VENTANA_CONSOLA)/2, ANCHO_VENTANA_CONSOLA, ALTO_VENTANA_CONSOLA, TRUE);
    SetConsoleTitleA("Sistema de deportes de la FEU-CUJAE de la Facultad de Inform\240tica");
}

void cambiarVisibilidadCursor(bool visible){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = visible;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void moverCursor(int x,int y){
    COORD cursorCoordenadas;
    cursorCoordenadas.X=x;
    cursorCoordenadas.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoordenadas);
}

void modificarTamanyoBuffer(int bufferX, int bufferY){
    COORD coordenadasBuffer;
    coordenadasBuffer.X = bufferX;
    coordenadasBuffer.Y = bufferY;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coordenadasBuffer);
}

void imprimirExtremosMarco(int coordenada_X_Marco, int coordenada_Y_Marco,int coordenada_X_Final_Marco, int formatoMarco){
    //formatoMarco:0->Formato Principio; 1->Formato Final
    int i;

    moverCursor(coordenada_X_Marco,coordenada_Y_Marco);
    for(i=1;i<=coordenada_X_Final_Marco-coordenada_X_Marco+1;i++){
        if(i==1)
            printf("%c", formatoMarco==0 ? 201 : 200);
        else if(i==coordenada_X_Final_Marco-coordenada_X_Marco+1)
            printf("%c", formatoMarco==0 ? 187 : 188);
        else
            printf("%c", 205);
    }
}

void imprimirCuerpoMarco(int coordenada_X_Marco ,int coordenada_Y_Marco,int coordenada_X_Final_Marco){

    moverCursor(coordenada_X_Marco,coordenada_Y_Marco);
    printf("%c", 186);
    moverCursor(coordenada_X_Final_Marco,coordenada_Y_Marco);
    printf("%c", 186);
}

void imprimirUnionCuerpoExtremosMarco(int coordenada_X_Marco, int coordenada_Y_Marco,int coordenada_X_Final_Marco){
    int i;

    moverCursor(coordenada_X_Marco,coordenada_Y_Marco);
    for(i=1;i<=coordenada_X_Final_Marco-coordenada_X_Marco+1;i++){
        if(i==1)
            printf("%c", 204);
        else if(i==coordenada_X_Final_Marco-coordenada_X_Marco+1)
            printf("%c", 185);
        else
            printf("%c", 205);
    }
}

void imprimirMarcoGeneral(int formatoMarco, int limpiarPantalla, COORD posicionMarco,int altoMarco){
    //formatoMarco:0->Formato Seleccionar; 1->Formato Pregunta; 2->Formato Error; 3->Formato Advertencia;
    //4->Formato Información
    //limpiarPantalla:0->No Limpiar la pantalla; 1->Limpiar la pantalla
    int i;

    if(limpiarPantalla==1)
        system("cls");
    modificarTamanyoBuffer(BUFFER_INTPR_X,BUFFER_INTPR_Y);
    if(formatoMarco==1)
        modificarColor(AZUL_VERDE);
    else if(formatoMarco==2)
        modificarColor(ROJO);
    else if(formatoMarco==3)
        modificarColor(AMARILLO);
    else if(formatoMarco==4)
        modificarColor(AZUL_CLARO);

    //INICIO DEL MARCO
    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y,posicionMarco.X+LONG_ANCHO_MARCO, 0);
    moverCursor(posicionMarco.X,posicionMarco.Y+1);
    printf("%c", 186);
    if(formatoMarco==2){
        moverCursor((LONG_ANCHO_MARCO-5)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("ERROR\a");
    }
    else if(formatoMarco==3){
        moverCursor((LONG_ANCHO_MARCO-11)/2+1+posicionMarco.X,posicionMarco.Y+1);
        printf("ADVERTENCIA");
    }

    moverCursor(posicionMarco.X+LONG_ANCHO_MARCO,posicionMarco.Y+1);
    printf("%c", 186);
    imprimirUnionCuerpoExtremosMarco(posicionMarco.X,posicionMarco.Y+2,posicionMarco.X+LONG_ANCHO_MARCO);

    //CUERPO DEL MARCO
    for(i=0;i<altoMarco-5;i++)
        imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+3+i,posicionMarco.X+LONG_ANCHO_MARCO);
    if(formatoMarco==0){
        modificarColor(BLANCO);
        moverCursor((LONG_ANCHO_MARCO-54)/2+1+posicionMarco.X,posicionMarco.Y+3);
        printf("Seleccione una de las opciones listadas a continuaci\242n:");
        modificarColor(REINICIAR_COLOR);
    }
    else if(formatoMarco==2){
        moverCursor((LONG_ANCHO_MARCO-22)/2+1+posicionMarco.X,posicionMarco.Y+3);
        modificarColor(BLANCO);
        printf("Explicaci\242n del error:");
        modificarColor(ROJO);
    }

    //FIN DEL MARCO
    imprimirUnionCuerpoExtremosMarco(posicionMarco.X,altoMarco-2+posicionMarco.Y,posicionMarco.X+LONG_ANCHO_MARCO);
    moverCursor(posicionMarco.X,altoMarco-1+posicionMarco.Y);
    printf("%c >>", 186);
    moverCursor(posicionMarco.X+LONG_ANCHO_MARCO,altoMarco-1+posicionMarco.Y);
    printf("%c", 186);
    imprimirExtremosMarco(posicionMarco.X,posicionMarco.Y+altoMarco,posicionMarco.X+LONG_ANCHO_MARCO,1);

    modificarColor(BLANCO);
}

void imprimirMarcoSimple(COORD posicionMarco){
    int i;

    system("cls");

    imprimirExtremosMarco(posicionMarco.X, posicionMarco.Y,posicionMarco.X+LONG_ANCHO_MARCO, 0);

    for(i=0;i<LONG_ALTO_MARCO-1;i++){
        imprimirCuerpoMarco(posicionMarco.X, posicionMarco.Y+1+i,posicionMarco.X+LONG_ANCHO_MARCO);
    }

    imprimirExtremosMarco(posicionMarco.X,posicionMarco.Y+LONG_ALTO_MARCO,posicionMarco.X+LONG_ANCHO_MARCO,1);
}

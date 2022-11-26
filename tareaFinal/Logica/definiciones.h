#ifndef DEFINICIONES_H
#define DEFINICIONES_H
//Cualquier cambio que se realice debe hacerse tomando en cuenta sus consecuencias en la correcta ejecución del programa

//Colores                                     //Código de colores:
#define ROJO 12                              //Rojo-> Errores
#define BLANCO 15                           //Blanco(Brillante)-> Impresión en general
#define AZUL_CLARO 11                      //Azul Claro-> Mostrar Información
#define VERDE 10                          //Verde-> Diferenciar datos principales, datos válidos
#define AMARILLO 14                      //Amarillo-> Advertencias
#define AZUL 9                          //Azul (Oscuro)-> Diferenciar participantes masculinos
#define AZUL_VERDE 3                   //Azul_Verde-> Pedidos al Usuario
#define ROSADO 13                     //Rosado-> Diferenciar participantes femeninas
#define NEGRO 0                      //Negro-> Logo Orqui Fondo
#define REINICIAR_COLOR 7           //Blanco (Estándar)-> Impresión de marcos e introducción del usuario

//Constantes Estructura Base de Datos |NO MODIFICAR PARA EL CORRECTO FUNCIONAMIENTO DEL PROGRAMA|
#define CANT_DATOS_PERSONALES_BD 50
#define CANT_MAX_DEPORTES 15   //Este dato puede ser modificado con precaución
//Tamaños Lógicos (Dichos valores deben ser mayor que 0 para evitar divisiones por 0 y otros problemas)
#define MAX_NOMBRE_APELLIDO_DEPORTE_BD 20
#define MAX_LONG_CADENA_CARACTERES 30
#define CANT_MAX_PARTICIPANTES 50
#define CANT_MIN_PARTICIPANTES 20
#define CANTIDAD_ANYOS_MAX 40   //Debe ser igual o mayor que la cantidad de años mínima (año actual-año de fundación de la facultad de informática)
#define CANTIDAD_ANYOS_MIN 10  //Debe ser igual o menor que la cantidad de años mínima (año actual-año de fundación de la facultad de informática)
//Definiciones de Consola General
#define ALTO_VENTANA_CONSOLA 600
#define ANCHO_VENTANA_CONSOLA 1000
//Definiciones de Buffer Inicio,Salida y Orqui
#define BUFFER_SIMPLE_X 150
#define BUFFER_SIMPLE_Y 150
//Definiciones de Buffer Interfaz Principal y Reportes Menores
#define BUFFER_INTPR_X 300
#define BUFFER_INTPR_Y 200
//Definiciones de Buffer Reporte Mostrar General
#define BUFFER_RPT_X 300
#define BUFFER_RPT_Y 6000
//Definiciones de Impresión General
#define LONG_ANCHO_MARCO 100
#define LONG_ALTO_MARCO 25
//Definiciones de Impresión Inicio
#define RETARDO_LOGO_FEU 5
#define ESPERA_VISUALIZACION_INICIO 700
#define RETARDO_UC_INICIO 80
#define RETARDO_CARGA_INICIO 75
#define ESPERA_VISUALIZACION_CARGA 700
//Definiciones de Impresión Orqui
#define RETARDO_LOGO_ORQUI 3
//Definiciones de Impresión Salida
#define RETARDO_SALIDA 100
#define CANT_ANIMACIONES 7
#define ESPERA_SALIDA 2000
//Otras Definiciones
#define TAMANYO_PTR_CHAR_ARR 4      //Este valor representa el tamaño lógico del arreglo de ptrs char (como tipo de
#define TAM_CHAR_VAR_VALIDAR 8     //variable), pues no es  posible determinarlo  de forma directa, y como en casi
#define TAM_CHAR_VAR_COMANDO 15   //todos  los sistemas  es igual a 4 bytes, se toma  este valor  como referencia
#define ANYO_FUNDACION_FAC_INF 2007
#endif // DEFINICIONES_H

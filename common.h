# ifndef COMMON_H
# define COMMON_H

#include <stdbool.h>

 // Definicion del enum para los estados de la pieza
 typedef enum {
    STATUS_APROBADA , // Pieza aprobada
    STATUS_RECHAZADA_LEVE , // Rechazo por defecto
    STATUS_RECHAZADA_GRAVE , // Rechazo por defecto
    STATUS_RECHAZADA_PESO , // Rechazo por peso
    STATUS_RECHAZADA_VOLUMEN , // Rechazo por volumen
    STATUS_RECHAZADA_PESO_VOLUMEN // Rechazo por peso
} PieceStatus ;

 // Definicion de la estructura principal para una pieza
struct Piece {
    int id ; // Identificador unico
    float weight ; // Peso en gramos
    int defects [5]; // 5 puntos de inspeccion (0:sin defecto , 1: leve , 2: grave )
    float dimensions [3]; // Largo , ancho , alto en cm
    int stationTimes [4]; // Tiempos de procesamiento por estacion ( ms )
    PieceStatus status ; // Estado de la pieza
    bool isProcessed ; // Indica si la pieza ha sido procesada
};

// Estructura para almacenar destinos de clasificacion
struct Destination {
    int cinta1 ; // Piezas aprobadas
    int cinta2 ; // Piezas con defectos leves o tiempo excesivo
    int cinta3 ; // Piezas con defectos graves
};

// Constantes comunes
# define MAX_WEIGHT 120.0 // Peso maximo aceptable ( g )
# define MIN_WEIGHT 60.0 // Peso minimo aceptable ( g )
# define MAX_VOLUME 1000.0 // Volumen maximo aceptable (cm ^3)
# define NUM_STATIONS 4 // Numero de estaciones de procesamiento

# endif


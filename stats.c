#include <stdio.h> // Incluye la biblioteca estándar para entrada y salida
#include "common.h"
#include "stats.h"

int totalPieces = 0; // Contador de piezas procesadas en total
float totalWeight = 0.0; // Acumulador del peso total de las piezas
int totalTimeStations[NUM_STATIONS] = {0}; // Array para almacenar tiempos acumulados por estación

float calculateAverage(int values[], int size) {
    // La función recibe el número entero del array en la posición n-1 ya que empieza en el 0 y su tamaño "size"
    int sum = 0; // Variable para almacenar la suma de los valores en el array

    for (int i = 0/* declaramos variable i=0 */; i < size /*recorre hasta el tamaño */; i++ /*aumenta el índice iterando sobre cada elemento del array*/) { //
        sum += values[i]; // Acumula la suma de los valores en la variable "sum"
    }
    return (size > 0) ? (float)sum / size : 0.00; /* Si size es>0 devuelve el valor decimal de la media, de lo contrario devuelve 0.00*/
}



/* Función para actualizar estadísticas con una nueva pieza */
void updateStats(struct Piece *piece, struct Destination *dest) {
    // La función recibe punteros a una estructura "Piece" y "Destination"
    totalPieces++; // Incrementa el contador de piezas procesadas
    totalWeight += piece->weight; // Suma el peso de la nueva pieza al peso total acumulado

    // Recorre todas las estaciones para acumular los tiempos de procesamiento
    for (int i = 0; i < NUM_STATIONS; i++) {
        totalTimeStations[i] += piece->stationTimes[i]; // Suma el tiempo en cada estación correspondiente
    }
}

/* Función para imprimir estadísticas finales */
void printStats() {
    printf("\n--- Reporte de Estadísticas ---\n"); // Imprime el encabezado del reporte
    printf("Total de piezas procesadas: %d\n", totalPieces); // Muestra el total de piezas procesadas

    // Imprime el peso promedio de las piezas procesadas
    // Usa el operador ternario para evitar división por cero si no hay piezas
    printf("Peso promedio: %.2f g\n", totalPieces > 0 ? totalWeight / totalPieces : 0.0);

    printf("Tiempos promedio por estación:\n"); // Encabezado para los tiempos por estación
    for (int i = 0; i < NUM_STATIONS; i++) { // Itera sobre las estaciones
        // Llama a calculateAverage para calcular el tiempo promedio de cada estación
        // Si no hay piezas, devuelve 0 para evitar división por cero
        printf("Estación %d: %.2f ms\n", i + 1, calculateAverage(totalTimeStations, totalPieces));
    }
}


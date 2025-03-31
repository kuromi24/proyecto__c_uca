#include <stdio.h> // Incluye la biblioteca est�ndar para entrada y salida
#include "common.h"
#include "stats.h"

float calculateAverage(int values[], int size) {
    // La funci�n recibe el n�mero entero del array en la posici�n n-1 ya que empieza en el 0 y su tama�o "size"
    int sum = 0; // Variable para almacenar la suma de los valores en el array

    for (int i = 0/* declaramos variable i=0 */; i < size /*recorre hasta el tama�o */; i++ /*aumenta el �ndice iterando sobre cada elemento del array*/) { //
        sum += values[i]; // Acumula la suma de los valores en la variable "sum"
    }
    return (size > 0) ? (float)sum / size : 0.00; /* Si size es>0 devuelve el valor decimal de la media, de lo contrario devuelve 0.00*/
}



/* Funci�n para actualizar estad�sticas con una nueva pieza */
void updateStats(struct Piece *piece, struct Destination *dest) {
    // La funci�n recibe punteros a una estructura "Piece" y "Destination"
    totalPieces++; // Incrementa el contador de piezas procesadas
    totalWeight += piece->weight; // Suma el peso de la nueva pieza al peso total acumulado

    // Recorre todas las estaciones para acumular los tiempos de procesamiento
    for (int i = 0; i < NUM_STATIONS; i++) {
        totalTimeStations[i] += piece->stationTimes[i]; // Suma el tiempo en cada estaci�n correspondiente
    }
}

/* Funci�n para imprimir estad�sticas finales */
void printStats() {
    printf("\n--- Reporte de Estad�sticas ---\n"); // Imprime el encabezado del reporte
    printf("Total de piezas procesadas: %d\n", totalPieces); // Muestra el total de piezas procesadas

    // Imprime el peso promedio de las piezas procesadas
    // Usa el operador ternario para evitar divisi�n por cero si no hay piezas
    printf("Peso promedio: %.2f g\n", totalPieces > 0 ? totalWeight / totalPieces : 0.0);

    printf("Tiempos promedio por estaci�n:\n"); // Encabezado para los tiempos por estaci�n
    for (int i = 0; i < NUM_STATIONS; i++) { // Itera sobre las estaciones
        // Llama a calculateAverage para calcular el tiempo promedio de cada estaci�n
        // Si no hay piezas, devuelve 0 para evitar divisi�n por cero
        printf("Estaci�n %d: %.2f ms\n", i + 1, calculateAverage(totalTimeStations, totalPieces));
    }
}


#ifndef STATS_H
#define STATS_H

float calculateAverage(int values[], int size);
int totalPieces = 0; // Contador de piezas procesadas en total
float totalWeight = 0.0; // Acumulador del peso total de las piezas
int totalTimeStations[NUM_STATIONS] = {0}; // Array para almacenar tiempos acumulados por estación
void updateStats(struct Piece *piece, struct Destination *dest);
void printStats();

#endif // STATS_H

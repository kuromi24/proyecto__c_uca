#ifndef CLASSIFY_H
#define CLASSIFY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "common.h"


int getTotalTime(int stationTimes[],int size); //Inizializamos la funcion , sumando los tiempos por estación, el size es NUM_STATIONS

void classifyPiece(struct Piece piezas,struct Destination *destino);

/*Para generalizar la funcion getTotalTime, utilizamos la variable station times sin puntero, por lo que cuando la utilizamos
para classifyPiece no llamamos al puntero de la estructura.
También podemos hacer esto ya que no modificamos el stationTimes */



#endif // classify_h

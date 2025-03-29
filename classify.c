#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "common.h"
#include "classify.h"


int getTotalTime(int stationTimes[],int size){
    int acumulador = 0;//Creamos una variable local que guarde la suma
    for(int i = 0;i<=(size-1);i++){
        acumulador += stationTimes[i];
    }
    return acumulador;
}


void classifyPiece(struct Piece piezas,struct Destination *destino){
    bool rechazada = (piezas.status ==STATUS_RECHAZADA_GRAVE || piezas.status == STATUS_RECHAZADA_PESO || piezas.status == STATUS_RECHAZADA_VOLUMEN || piezas.status ==STATUS_RECHAZADA_PESO_VOLUMEN);
    int acumulador = 0;//Recoge el tiempo total de las estaciones
    acumulador = getTotalTime(piezas.stationTimes,NUM_STATIONS);

    if(acumulador < 1000 && piezas.status == STATUS_APROBADA ){
        destino->cinta1 += 1;
    }else if((acumulador >= 1000 || piezas.status == STATUS_RECHAZADA_LEVE) && !(rechazada) ){
        destino->cinta2 += 1;
    }else{ //Si la pieza es rechazada es llevada a la cinta 3
        destino->cinta3 += 1;

    }
}

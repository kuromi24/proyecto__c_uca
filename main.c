#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "classify.h"

//Main de testbench para comprobar rapidamente la funcion

int main()
{

    struct Piece pieza ={
        .stationTimes = {90,100,100,100},
        .status = STATUS_APROBADA
    };
    struct Destination destinos = {
        .cinta1 = 0,
        .cinta2 = 0,
        .cinta3 = 0,
    };

    struct Piece pieza2 ={
        .stationTimes = {9000,100,100,100},
        .status = STATUS_APROBADA
    };

    struct Piece pieza3 ={
        .stationTimes = {90,100,100,100},
        .status = STATUS_RECHAZADA_GRAVE
    };

    struct Piece pieza4 ={
        .stationTimes = {90,100,100,100},
        .status = STATUS_RECHAZADA_GRAVE
    };

    struct Piece pieza5 ={
        .stationTimes = {9000,100,100,100},
        .status = STATUS_RECHAZADA_GRAVE
    };

    classifyPiece(pieza,&destinos);
    classifyPiece(pieza2,&destinos);
    classifyPiece(pieza3,&destinos);
    classifyPiece(pieza4,&destinos);
    classifyPiece(pieza5,&destinos);

    printf("%d\n",destinos.cinta1);
    printf("%d\n",destinos.cinta2);
    printf("%d\n",destinos.cinta3);
    return 0;
}





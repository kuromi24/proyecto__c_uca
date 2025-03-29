#include <stdio.h>
#include "defects.h"
#include "common.h"


void checkDefects(struct Piece *piece) {
	int graves=0, leves=0;

	printf("Analisis de defectos de las piezas \n");
	graves=countDefects(piece->defects,5,2);
	leves=countDefects(piece->defects,5, 1);
	if (graves>0) {
	    
		piece->status=STATUS_RECHAZADA_GRAVE;
	} else if(graves==0 && leves<=2) {
	    
		piece->status=STATUS_APROBADA;
	} else if(graves==0 && leves>2) {
	    
		piece->status=STATUS_RECHAZADA_LEVE;
	}
}

int countDefects(int defects[], int size, int type) {
	int suma=0;
	for (int i=0; i<size; i++) {
		if (defects[i]==type) {
			suma++;
		} else {
			continue;
		}
	}
	return suma;
}

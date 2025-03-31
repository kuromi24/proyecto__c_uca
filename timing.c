#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "timing.h"
int calculateTime(float weight, float volume, float dimensions[],int station);
void setStationTimes(struct Piece *piece);

void setStationTimes(struct Piece *piece){
    for (int i=1;i<5;i++){
        piece->stationTimes[i-1]= calculateTime(piece->weight,piece->volume,piece->dimensions,i);
    }
}
/*Se analiza en i-1 ya que las estaciones van de la 1 a la 4*/

int calculateTime(float weight, float volume, float dimensions[],int station){
    int stationt;
                if (station == 1){
                        stationt = (weight * 0.5) + (volume / 100);

                }
                else if (station==2){
                        stationt = (weight * 0.3) + (dimensions[0] * 0.2);
                }
                else if (station==3){
                        stationt = (dimensions[1] * 0.4) + (dimensions[2] * 0.3);
                }
                else if (station==4){
                        stationt = (weight * 0.2) + (volume / 200);
                }
return stationt;
}

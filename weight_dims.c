#include "common.h"
#include "weight_dims.h"


void measureWeightAndDims(struct Piece *piece){

float volume=calculateVolume(piece->dimensions);


    if ((piece->status==STATUS_APROBADA)&&(volume <MAX_VOLUME)&&(((piece->weight <MAX_WEIGHT)&&(piece->weight >MIN_WEIGHT)))){

        piece->status= STATUS_APROBADA;}

    else if ((volume>=MAX_VOLUME)&&(((piece->weight)<MAX_WEIGHT)&&(piece->weight>MIN_WEIGHT))){

        piece->status= STATUS_RECHAZADA_VOLUMEN;}

    else if (((volume<MAX_VOLUME)&&((piece->weight<=MIN_WEIGHT)||(piece->weight>=MAX_WEIGHT)))){

       piece->status= STATUS_RECHAZADA_PESO;}

    else{

       piece->status= STATUS_RECHAZADA_PESO_VOLUMEN;}

}
float calculateVolume(float dimensions[3]){

return (dimensions[0])*(dimensions[1])*(dimensions[2]);
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#inculde "piece_gen.h"
//Funcion auxiliar para validar dimensiones  (largo>ancho>alto)

bool validateDimensions(float dimensions[3]){
    return (dimensions[0] > dimensions[1] && dimensions[1] > dimensions[2]);
}

//Funcion principal para generar una pieza con valores aleatorios
void generatePiece(struct Piece *piece) {
    // Semilla para generar numeros aleatorios. Variable estatica que indica si la semilla ya fue iniciada
    static int seeded = 0;
    //Verificar si la semilla aun no ha sido establecida
    if (!seeded) {
        srand(time(NULL));//Inicializa la semilla del generador de numeros aleatorios con la hora actual
        seeded = 1;//Marca la semilla como inicializada para evitar que se vuelva a establecer
    }

    //Asignamos un id unico
    static int nextID = 0;
    piece->id = nextID++;

    //Generamos pesos aleatorios entre 50 y 150 gramos
    piece->weight = 50.0 + (rand()% 101) / 1.0; //  50.0 a 150.0 de 1 en 1.

    //Generamos defectos (0: sin defectos, 1: leve, 2: grave) para 5 puntos de inspeccion
    for (int i = 0;i < 5; i++){
        piece->defects[i] = rand() % 3; //Valores entre 0 y 2
    }

    // Generamos dimensiones (largo: 10-50 cm, ancho: 5-30 cm, alto: 5-20 cm) mediante el uso de un do while
    do{
        piece->dimensions[0] = 10.0 + (rand() % 41) / 1.0; //Largo de 10-50 cm
        piece->dimensions[1] = 5.0 + (rand() % 26) / 1.0; //Ancho de 5-30 cm
        piece->dimensions[2]= 5.0 + (rand() % 16) / 1.0; //Alto: 5-20 cm
        } while (!validateDimensions(piece->dimensions));




}

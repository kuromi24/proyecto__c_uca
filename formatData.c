#include <stdio.h>
#include <string.h>
#include "common.h"
#include "formatData.h"

// Función principal para formatear los datos de una pieza
void formatData(struct Piece *piece, char *buffer, int bufferSize) {
    // Determinar el texto del estado de la pieza
    const char *statusStr;
    switch (piece->status) {
        case STATUS_APROBADA: statusStr = "APROBADA"; break;
        case STATUS_RECHAZADA_LEVE: statusStr = "RECHAZADA LEVE"; break;
        case STATUS_RECHAZADA_GRAVE: statusStr = "RECHAZADA GRAVE"; break;
        case STATUS_RECHAZADA_PESO: statusStr = "RECHAZADA PESO"; break;
        case STATUS_RECHAZADA_VOLUMEN: statusStr = "RECHAZADA VOLUMEN"; break;
        case STATUS_RECHAZADA_PESO_VOLUMEN: statusStr = "RECHAZADA PESO Y VOLUMEN"; break;
        default: statusStr = "DESCONOCIDO"; break;
    }

    // Crear la cadena formateada usando solo snprintf
    snprintf(buffer, bufferSize,
             "ID: %d, Peso: %.1fg, Defectos: %d-%d-%d-%d-%d, Dimensiones: %.1fx%.1fx%.1fcm, Tiempos: %d-%d-%d-%dms, Status: %s",
             piece->id, piece->weight,
             piece->defects[0], piece->defects[1], piece->defects[2],
             piece->defects[3], piece->defects[4],
             piece->dimensions[0], piece->dimensions[1], piece->dimensions[2],
             piece->stationTimes[0], piece->stationTimes[1],
             piece->stationTimes[2], piece->stationTimes[3],
             statusStr);
}

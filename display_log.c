#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "display_log.h"



void displayAndLog(char *message) {
    printf("%s\n", message);
    writeToLog(message);
}

void writeToLog(char *message) {
    FILE *file = fopen("production_log.txt", "a");
    if (file == NULL) {
        printf("** Error al abrir el archivo **\n");
        return -1;
    }

    // Timestamp
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", t);

    fprintf(file, "%s %s\n", timestamp, message);
    fclose(file);
}

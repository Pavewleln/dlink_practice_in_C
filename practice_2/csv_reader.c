#include "include/csv_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для чтения данных из CSV-файла
csv_data_t* read_csv_file(const char* file_name) {
    csv_data_t* csv_data = (csv_data_t*)malloc(sizeof(csv_data_t));
    if (csv_data == NULL) {
        return NULL;
    }
    csv_data->num_rows = 0;
    csv_data->num_cols = 0;
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        free(csv_data);
        return NULL;
    }
    char line[1024];
    while (fgets(line, 1024, fp) && csv_data->num_rows < MAX_CSV_ROWS) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        char* tok = strtok(line, ",");
        int col = 0;
        while (tok && col < MAX_CSV_COLS) {
            csv_data->data[csv_data->num_rows][col] = (char*)malloc(strlen(tok)+1);
            strcpy(csv_data->data[csv_data->num_rows][col], tok);
            tok = strtok(NULL, ",");
            col++;
        }
        if (col > csv_data->num_cols) {
            csv_data->num_cols = col;
        }
        csv_data->num_rows++;
    }
    fclose(fp);
    return csv_data;
}
#include "include/txt_file_generator.h"

// Функция для генерации текстового файла без запятых
int generate_txt_file(const char* file_name, const csv_data_t* csv_data) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        return -1;
    }
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_cols; j++) {
            fprintf(fp, "%s", csv_data->data[i][j]);
            if (j != csv_data->num_cols-1) {
                fprintf(fp, "\t");
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
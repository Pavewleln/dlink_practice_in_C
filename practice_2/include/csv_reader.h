#ifndef CSV_READER_H
#define CSV_READER_H

#include "common.h"

#define MAX_CSV_ROWS 1000
#define MAX_CSV_COLS 100

typedef struct {
    int num_rows;
    int num_cols;
    char* data[MAX_CSV_ROWS][MAX_CSV_COLS];
} csv_data_t;

csv_data_t* read_csv_file(const char* file_name);

#endif
#ifndef C_FILE_GENERATOR_H

#include "csv_reader.h"

#define C_FILE_GENERATOR_H

#define OUTPUT_FILE_TYPE_C 1

int generate_c_file(const char *file_name, const csv_data_t *csv_data);

#endif
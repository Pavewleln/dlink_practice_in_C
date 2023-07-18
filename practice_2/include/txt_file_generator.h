#ifndef TXT_FILE_GENERATOR_H

#include "csv_reader.h"

#define TXT_FILE_GENERATOR_H

#define OUTPUT_FILE_TYPE_TXT 2

int generate_txt_file(const char* file_name, const csv_data_t* csv_data);

#endif
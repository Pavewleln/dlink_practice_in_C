#ifndef HTML_FILE_GENERATOR_H

#include "csv_reader.h"

#define HTML_FILE_GENERATOR_H

#define OUTPUT_FILE_TYPE_HTML 3

int generate_html_file(const char* file_name, const csv_data_t* csv_data);

#endif
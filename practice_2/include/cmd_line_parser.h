#ifndef CMD_LINE_PARSER_H

#include "csv_reader.h"

#define CMD_LINE_PARSER_H

int parse_cmd_line(int argc, char *argv[], char **output_file_name, int *output_file_type);

#endif
#include "include/cmd_line_parser.h"

// Функция для парсинга командной строки
int parse_cmd_line(int argc, char* argv[], char** output_file_name, int* output_file_type) {
    if(argc != 5) {
        return -1;
    }
    if(strcmp(argv[2], "-o") != 0) {
        return -2;
    }
    if(atoi(argv[4]) < 1 || atoi(argv[4]) > 3) {
        return -3;
    }
    *output_file_name = argv[3];
    *output_file_type = atoi(argv[4]);
    return 0;
}
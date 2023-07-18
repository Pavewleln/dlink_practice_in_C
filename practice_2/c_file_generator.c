#include "include/c_file_generator.h"

// Функция для генерации файла на языке C
int generate_c_file(const char* file_name, const csv_data_t* csv_data) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "#include <stdio.h>\n\n");
    fprintf(fp, "int main() {\n");
    for (int i = 0; i < csv_data->num_rows; i++) {
        fprintf(fp, "\tprintf(\"");
        for (int j = 0; j < csv_data->num_cols; j++) {
            fprintf(fp, "%s\\t", csv_data->data[i][j]);
        }
        fprintf(fp, "\\n\");\n");
    }
    fprintf(fp, "\treturn 0;\n");
    fprintf(fp, "}\n");
    fclose(fp);
    return 0;
}
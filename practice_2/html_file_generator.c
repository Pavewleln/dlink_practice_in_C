#include "include/html_file_generator.h"

// Функция для генерации HTML-файла
int generate_html_file(const char* file_name, const csv_data_t* csv_data) {
    FILE* fp = fopen(file_name, "w");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "<title>%s</title>\n", file_name);
    fprintf(fp, "</head>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<table>\n");
    for (int i = 0; i < csv_data->num_rows; i++) {
        fprintf(fp, "<tr>\n");
        for (int j = 0; j < csv_data->num_cols; j++) {
            fprintf(fp, "<td>%s</td>\n", csv_data->data[i][j]);
        }
        fprintf(fp, "</tr>\n");
    }
    fprintf(fp, "</table>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");
    fclose(fp);
    return 0;
}
#include "include/common.h"
#include "include/csv_reader.h"
#include "include/cmd_line_parser.h"
#include "include/c_file_generator.h"
#include "include/txt_file_generator.h"
#include "include/html_file_generator.h"

int main(int argc, char *argv[])
{
    char *input_file_name = argv[1];
    char *output_file_name;
    int output_file_type;
    int parse_cmd_result = parse_cmd_line(argc, argv, &output_file_name, &output_file_type);
    if (parse_cmd_result != 0)
    {
        printf("Use the notation: %s input_file_name -o output_file_name output_file_type(txt, html, c)\n", argv[0]);
        return parse_cmd_result;
    }

    csv_data_t *csv_data = read_csv_file(input_file_name);
    if (csv_data == NULL)
    {
        printf("Error: file %s if empty \n", input_file_name);
        return -4;
    }

    if (strcmp(argv[4], "c") == 0)
    {
        generate_c_file(output_file_name, csv_data);
    }
    else if (strcmp(argv[4], "txt") == 0)
    {
        generate_txt_file(output_file_name, csv_data);
    }
    else if (strcmp(argv[4], "html") == 0)
    {
        generate_html_file(output_file_name, csv_data);
    }
    else
    {
        printf("Error: invalid output file type %d\n", output_file_type);
        return -5;
    }
    printf("Successfully generated output file %s\n", output_file_name);
    return 0;
}
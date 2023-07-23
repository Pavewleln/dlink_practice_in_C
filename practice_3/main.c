#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/html_parser.h"

int main(int argc, char **argv)
{
    char *html = NULL;
    size_t html_size = 0;
    char output[MAX_OUTPUT_SIZE];
    size_t output_size = 0;
    plugin_type_t plugin_type = PLUGIN_TYPE_TEXT;
    plugin_t plugin;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <plugin> <filename>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "text") == 0)
    {
        plugin_type = PLUGIN_TYPE_TEXT;
        plugin.process = strip_tags;
    }
    else if (strcmp(argv[1], "headers") == 0)
    {
        plugin_type = PLUGIN_TYPE_HEADERS;
        plugin.process = extract_headers;
    }
    else if (strcmp(argv[1], "links") == 0)
    {
        plugin_type = PLUGIN_TYPE_LINKS;
        plugin.process = extract_links;
    }
    else
    {
        fprintf(stderr, "Unknown plugin: %s\n", argv[1]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (!file)
    {
        fprintf(stderr, "Failed to open file: %s\n", argv[2]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    html_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    html = malloc(html_size);
    if (!html)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        fclose(file);
        return 1;
    }

    size_t n = fread(html, 1, html_size, file);
    if (n != html_size)
    {
        fprintf(stderr, "Failed to read file: %s\n", argv[2]);
        fclose(file);
        free(html);
        return 1;
    }

    fclose(file);

    parse_input(html, html_size, plugin_type, output, &output_size);

    fwrite(output, 1, output_size, stdout);

    free(html);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/plugins.h"

int main(int argc, char **argv)
{
    char *html = NULL;
    size_t html_size = 0;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <plugin> <filename>\n", argv[0]);
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

    if (strcmp(argv[1], "text") == 0)
    {
        only_text_plugin(html, html_size, file);
    }
    else if (strcmp(argv[1], "headers") == 0)
    {
        headers_plugin(html, html_size, file);
    }
    else if (strcmp(argv[1], "links") == 0)
    {
        links_plugin(html, html_size, file);
    }
    else
    {
        fprintf(stderr, "Unknown plugin: %s\n", argv[1]);
        return 1;
    }

    fclose(file);

    free(html);

    return 0;
}
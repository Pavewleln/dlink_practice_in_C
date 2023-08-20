#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void (*PluginFunction)(char *, size_t, FILE *);

int main(int argc, char **argv)
{
    char *html = NULL;
    size_t html_size = 0;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <plugin> <filename> <library>\n", argv[0]);
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

    void *library = dlopen(argv[3], RTLD_LAZY);

    if (!library)
    {
        fprintf(stderr, "Failed to load library: %s\n", dlerror());
        fclose(file);
        free(html);
        return 1;
    }
    PluginFunction plugin_function = (PluginFunction)dlsym(library, argv[1]);
    plugin_function(html, html_size, file);
    dlclose(library);
    fclose(file);

    free(html);

    return 0;
}
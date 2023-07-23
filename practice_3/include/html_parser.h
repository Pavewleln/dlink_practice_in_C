#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#define MAX_OUTPUT_SIZE 1024*1024

typedef enum {
    PLUGIN_TYPE_TEXT,
    PLUGIN_TYPE_HEADERS,
    PLUGIN_TYPE_LINKS
} plugin_type_t;

typedef struct {
    plugin_type_t type;
    void (*process)(const char *html, size_t html_size, char *output, size_t *output_size);
} plugin_t;

void parse_input(const char *html, size_t html_size, plugin_type_t plugin_type, char *output, size_t *output_size);

void strip_tags(const char *html, size_t html_size, char *output, size_t *output_size);
void extract_headers(const char *html, size_t html_size, char *output, size_t *output_size);
void extract_links(const char *html, size_t html_size, char *output, size_t *output_size);

#endif
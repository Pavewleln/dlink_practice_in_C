#ifndef PLUGINS_H
#define PLUGINS_H
#define MAX_LINE_LENGTH 1000

void remove_tags(const char *html);
void only_text_plugin(const char *html, size_t *html_size, FILE *file);
void headers_plugin(const char *html, size_t *html_size, FILE *file);
void links_plugin(cconst char *html, size_t *html_size, FILE *file);

#endif

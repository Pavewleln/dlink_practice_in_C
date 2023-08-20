#ifndef PLUGINS_H
#define PLUGINS_H
#define MAX_LINE_LENGTH 1000

void remove_tags(const char *html);
void text(const char *html, size_t *html_size, FILE *file);
void headers(const char *html, size_t *html_size, FILE *file);
void links(const char *html, size_t *html_size, FILE *file);

#endif

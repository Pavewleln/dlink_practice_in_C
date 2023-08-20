#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/plugins.h"

void remove_tags(const char *html)
{
  int i = 0;
  int in_tag = 0;

  while (html[i] != '\0')
  {
    if (html[i] == '<')
    {
      in_tag = 1;
    }
    else if (html[i] == '>')
    {
      in_tag = 0;
    }
    else if (!in_tag)
    {
      putchar(html[i]);
    }

    i++;
  }
}

void text(const char *html, size_t *html_size, FILE *file)
{
  while (fgets(html, html_size, file))
  {
    remove_tags(html);
    putchar('\n');
  }
}

void headers(const char *html, size_t *html_size, FILE *file)
{
  while (fgets(html, html_size, file))
  {
    if (strstr(html, "<h1>") || strstr(html, "<h2>") || strstr(html, "<h3>") ||
        strstr(html, "<h4>") || strstr(html, "<h5>") || strstr(html, "<h6>"))
    {
      remove_tags(html);
      putchar('\n');
    }
  }
}

void links(const char *html, size_t *html_size, FILE *file)
{
  while (fgets(html, html_size, file))
  {
    if (strstr(html, "<a>"))
    {
      remove_tags(html);
      putchar('\n');
    }
  }
}
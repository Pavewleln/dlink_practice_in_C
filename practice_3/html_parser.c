#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "include/html_parser.h"

#define MAX_OUTPUT_SIZE 1024 * 1024
#define MAX_NUM_HEADERS 100
#define MAX_HEADER_SIZE 256
#define MAX_NUM_LINKS 100
#define MAX_LINK_SIZE 256

void strip_tags(const char *html, size_t html_size, char *output, size_t *output_size)
{
    int inside_tag = 0;
    size_t j = 0;

    for (size_t i = 0; i < html_size; i++)
    {
        if (html[i] == '<')
        {
            inside_tag = 1;
        }
        else if (html[i] == '>')
        {
            inside_tag = 0;
        }
        else if (inside_tag == 0)
        {
            output[j++] = html[i];
        }
    }

    // Добавляем завершающий нуль-символ в конец строки
    output[j] = '\0';
    *output_size = j;
}

void extract_headers(const char *html, size_t html_size, char *output, size_t *output_size)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    int level = 0;

    for (i = 0; i < html_size; i++)
    {
        if (html[i] == '<' && html[i + 1] == 'h')
        {
            level = html[i + 2] - '0';
            for (j = i + 3; j < html_size; j++)
            {
                if (html[j] == '>')
                {
                    i = j;
                    break;
                }
            }
            for (j = i + 1; j < html_size; j++)
            {
                if (html[j] == '<' && html[j + 1] == '/' && html[j + 2] == 'h')
                {
                    k = j + 3;
                    while (k < html_size && isspace(html[k]))
                    {
                        k++;
                    }
                    if (k == html_size || html[k] != level + '0')
                    {
                        break;
                    }
                    while (k < html_size && html[k] != '>')
                    {
                        k++;
                    }
                    if (k == html_size)
                    {
                        break;
                    }
                    i = j + 3;
                    for (; i < k; i++)
                    {
                        output[*output_size] = html[i];
                        (*output_size)++;
                    }
                    output[*output_size] = '\n';
                    (*output_size)++;
                    break;
                }
            }
        }
    }

    output[*output_size] = '\0';
}

void extract_links(const char *html, size_t html_size, char *output, size_t *output_size)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    char url[MAX_LINK_SIZE];

    for (i = 0; i < html_size; i++)
    {
        if (html[i] == '<' && html[i + 1] == 'a')
        {
            for (j = i + 2; j < html_size; j++)
            {
                if (html[j] == '>')
                {
                    i = j;
                    break;
                }
            }
            for (j = i + 1; j < html_size; j++)
            {
                if (html[j] == '<' && html[j + 1] == '/' && html[j + 2] == 'a')
                {
                    k = i + 2;
                    while (k < j && isspace(html[k]))
                    {
                        k++;
                    }
                    if (k == j)
                    {
                        break;
                    }
                    if (html[k] == 'h' && html[k + 1] == 'r' && html[k + 2] == 'e' && html[k + 3] == 'f')
                    {
                        k += 4;
                        while (k < j && isspace(html[k]))
                        {
                            k++;
                        }
                        if (k == j || html[k++] != '=')
                        {
                            break;
                        }
                        while (k < j && isspace(html[k]))
                        {
                            k++;
                        }
                        if (k >= j)
                        {
                            break;
                        }
                        if (html[k] == '"' || html[k] == '\'')
                        {
                            char delim = html[k++];
                            size_t l = 0;
                            while (k < j && html[k] != delim)
                            {
                                url[l++] = html[k++];
                            }
                            url[l] = '\0';
                            for (l = 0; l < strlen(url); l++)
                            {
                                output[*output_size] = url[l];
                                (*output_size)++;
                            }
                            output[*output_size] = '\n';
                            (*output_size)++;
                            break;
                        }
                    }
                }
            }
        }
    }

    output[*output_size] = '\0';
}

void parse_input(const char *html, size_t html_size, plugin_type_t plugin_type, char *output, size_t *output_size)
{
    switch (plugin_type)
    {
    case PLUGIN_TYPE_TEXT:
        strip_tags(html, html_size, output, output_size);
        break;
    case PLUGIN_TYPE_HEADERS:
        extract_headers(html, html_size, output, output_size);
        break;
    case PLUGIN_TYPE_LINKS:
        extract_links(html, html_size, output, output_size);
        break;
    default:
        output[0] = '\0';
        *output_size = 0;
        break;
    }
}
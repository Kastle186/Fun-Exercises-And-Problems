#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools/hackerrank.h"

int *matching_strings(int, char **, int, char **, int *);

int main(void)
{
    int strings_count = parse_int(ltrim(rtrim(readline())));
    char **strings = malloc(strings_count * sizeof(char *));

    for (int i = 0; i < strings_count; i++)
    {
        char *strings_item = readline();
        *(strings + i) = strings_item;
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));
    char** queries = malloc(queries_count * sizeof(char *));

    for (int i = 0; i < queries_count; i++)
    {
        char *queries_item = readline();
        *(queries + i) = queries_item;
    }

    int res_count;
    int *res = matching_strings(strings_count,
                               strings,
                               queries_count,
                               queries,
                               &res_count);

    for (int i = 0; i < res_count; i++)
    {
        printf("%d", *(res + i));

        if (i != res_count - 1)
            printf("\n");
    }
    printf("\n");

    for (int i = 0; i < strings_count; i++)
        free(*(strings + i));

    for (int i = 0; i < queries_count; i++)
        free(*(queries + i));

    free(strings);
    free(queries);
    free(res);

    return 0;
}

int *matching_strings(int strings_count,
                      char **strings,
                      int queries_count,
                      char **queries,
                      int *result_count)
{
    int *matches_count = calloc(queries_count, sizeof(int));

    for (int i = 0; i < queries_count; i++)
        *(matches_count + i) = 0;

    for (int j = 0; j < queries_count; j++)
    {
        char *query = *(queries + j);

        for (int k = 0; k < strings_count; k++)
        {
            char *string = *(strings + k);

            if (strcmp(query, string) == 0)
                matches_count[j]++;
        }
    }

    *result_count = queries_count;
    return matches_count;
}

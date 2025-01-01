#ifndef _COMPETITIVE_PROGRAMMING_INPUT_
#define _COMPETITIVE_PROGRAMMING_INPUT_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char *readline();
char *ltrim(char *);
char *rtrim(char *);
char **split_string(char *);
int parse_int(char *);
long parse_long(char *);

#endif // _COMPETITIVE_PROGRAMMING_INPUT_
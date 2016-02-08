/*
  little_elf
  (C) Andreas Gaiser, 2016

  types

*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"

string make_string(char* zero_terminated_string)
{
    string result = calloc(1, sizeof(struct string_value));
	size_t length = strlen(zero_terminated_string);
	result->content = calloc(length, sizeof(char));
	strncpy(result->content, zero_terminated_string, length);
	
	return result;
}

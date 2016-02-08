/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  structure of elf file 
*/

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t byte;
typedef uint32_t stdint;

typedef uint32_t error;

typedef size_t file_position;

typedef struct string_value
{
  char* content;
  size_t length;
} *string;


extern string make_string(char* zero_terminated_string);

#endif

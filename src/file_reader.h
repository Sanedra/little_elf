/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  file reading facilites
*/

#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"


typedef struct
{
  FILE *file;
  file_position position;

} file_reader;

/*
    file_reader interface
*/

/* Open the file and initialize the file reader structure. */
extern error file_reader_create(string filepath, file_reader** reader);

/* Read a sequence of bytes. */
extern error file_reader_read(file_reader* reader, byte* value, size_t byte_count);

/* Read a single byte. */
extern error file_reader_read_byte(file_reader* reader, byte* value);

/* Close the file reader. */
extern error file_reader_close(file_reader* reader);

#endif


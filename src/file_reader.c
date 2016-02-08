/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  file reading facilites
*/

#include <stdlib.h>

#include <stdio.h>

#include "file_reader.h"
#include "errors.h"


error file_reader_create(string filepath, file_reader** reader)
{
    FILE* file = fopen(filepath->content, "rb+");
    if (file == NULL)
    {
	    return ERROR_FILE_READER_OPEN_FAILED;
    }
    file_reader* result = calloc(1, sizeof(file_reader));
    result->file = file;
    result->position = 0;
    *reader = result;
    return ERROR_OK;
}

error file_reader_read(file_reader* reader, byte* value, size_t byte_count)
{
    size_t read_bytes = fread(value, sizeof(byte), byte_count, reader->file);
	if (read_bytes != byte_count)
    {
        return ERROR_FILE_READER_NOT_ALL_BYTES_READ;
    }
    return ERROR_OK;
}

error file_reader_read_byte(file_reader *reader, byte* value)
{
    return file_reader_read(reader, value, 1);
}

extern error file_reader_close(file_reader* reader)
{
    if (reader != NULL)
    {
	    fclose(reader->file);
    }
    return ERROR_OK;
}


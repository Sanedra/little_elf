/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  structure of elf file 
*/

#include "elf_file.h"
#include <stdlib.h>
#include "errors.h"

error read_elf_header(file_reader* reader, elf_header **header)
{
	elf_header *result = calloc(1, sizeof(elf_header));

	file_reader_read(reader, &(result->magic_number[0]), 4);
	file_reader_read(reader, &(result->class), 1);
	file_reader_read(reader, &(result->endianness), 1);
	file_reader_read(reader, &(result->version), 1);
	file_reader_read(reader, &(result->os_abi), 1);
	file_reader_read(reader, &(result->pad[0]), 7);
	file_reader_read(reader, &(result->type[0]), 2);
	file_reader_read(reader, &(result->e_machine[0]), 2);
	file_reader_read(reader, &(result->e_version[0]), 4);

	for (int i = 0; i < 4; ++i)
	{
		printf("MAGIC BYTE %d: %02x\n", i, result->magic_number[i]); 
	}
	printf("CLASS: %d\n", result->class);
	printf("ENDIANNESS: %d\n", result->endianness);
	printf("VERSION: %d\n", result->version);
	printf("OS_ABI: %d\n", result->os_abi);

	return ERROR_OK;
}

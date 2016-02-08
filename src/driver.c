
#include <stdio.h>

#include "types.h"
#include "file_reader.h"
#include "elf_file.h"


int main(void)
{
	string filename = make_string("elf.so");

	file_reader* reader;
	elf_header* header;

	error status;
	status = file_reader_create(filename, &reader);
	// printf(">>%d\n", reader->file);
	status = read_elf_header(reader, &header);

	status = file_reader_close(reader);
	
}

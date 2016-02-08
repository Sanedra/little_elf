/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  structure of elf file 
*/


#ifndef ELF_FILE_H
#define ELF_FILE_H

#include "types.h"
#include "file_reader.h"

#define ELF_HEADER_EI_MAG 0x0
#define ELF_HEADER_EI_CLASS 0x04
#define ELF_HEADER_EI_DATA 0x05
#define ELF_HEADER_EI_VERSION 0x06
#define ELF_HEADER_EI_OSABI 0x07
#define ELF_HEADER_EI_ABIVERSION 0x08


typedef struct _ELF_HEADER 
{
    byte magic_number[4]; /* magic number */
    byte class;           /* 1 = 32bit, 2 = 64bit */
    byte endianness;      /* 1 = little endianness, 2 = big endnanness */
    byte version;         /* 1 = original ELF */
    byte os_abi;          /* ABI Version */
    byte pad[7];          /* PAD (unused) */
    byte type[2];         /*
							1 = relocatable, 
							2 = executable,
							3 = shared,
							4 = core
						  */
    byte e_machine[2];    /* machine */
    byte e_version[4];    /* version */
 
} elf_header;


extern error read_elf_header(file_reader* reader, elf_header **header);

#endif

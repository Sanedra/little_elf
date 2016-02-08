/*
  little_elf
  (C) Andreas Gaiser, 2016

  elf_file
  structure of elf file 
*/

#ifndef ERRORS_H
#define ERRORS_H

typedef uint32_t errorcode;

#define ERROR_OK 0x0

#define ERROR_FILE_READER_OPEN_FAILED 0x01
#define ERROR_FILE_READER_EOF_REACHED 0x03
#define ERROR_FILE_READER_NOT_ALL_BYTES_READ 0x04

#endif

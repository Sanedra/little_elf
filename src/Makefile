CC              = gcc
COMPILE_OPTIONS = -std=c99 -Wall -g
LDFLAGS         = -lm -lpthread
OUTPUT_DIR      = ../bin
APP_NAME        = little_elf


MODULES         = types file_reader elf_file driver
OBJ             = $(MODULES:%=%.o)
SRC             = $(MODULES:%=%.c)

%.o: %.c %.h
	$(CC) $(COMPILE_OPTIONS) -c $< -o $@

compile: $(OBJ)
	$(CC) $(COMPILE_OPTIONS) -o $(OUTPUT_DIR)/$(APP_NAME) $(OBJ) $(LDFLAGS)

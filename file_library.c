#include "file_library.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/* read_file reads a string of bytes into memory
 * at the location provided by contents.
 */
size_t read_file(char* file_name, char** contents){
	struct stat st;
	stat(file_name, &st);
	FILE* file = fopen(file_name, "r");
	*contents = (char*) malloc(st.st_size * sizeof(char));
	size_t num_bytes = fread(*contents, st.st_size, 1, file);
	fclose(file);
	return st.st_size;
}

/* write_file writes a string of bytes to disk */
size_t write_file(char* file_name, char* contents, size_t size){

	// This function is from Luke4211 on the class discord
	// It removes the newline character from the filename
	char *rmv = strchr(file_name, '\n');
	if (rmv) *rmv = 0;

	// "wb" found on www.tutorialspoint.com/cprogramming/c_file_io
	FILE* file = fopen(file_name, "wb");
	for (int i = 0; i < size; i++)
		fwrite(contents, 1, size, file);
	fclose(file);
	return size;
}

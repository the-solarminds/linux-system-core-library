#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read file content into a buffer
char* read_file(const char* filename);

// Function to write content to a file
int write_file(const char* filename, const char* content);

// Function to get file size
long get_file_size(const char* filename);

#endif // FILE_UTILS_H 
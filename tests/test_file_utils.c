#include "../include/file_utils.h"
#include <stdio.h>

int main() {
    const char* test_filename = "test.txt";
    const char* test_content = "Hello, Linux System Core Library!";

    // Test write_file
    printf("Writing to file...\n");
    if (write_file(test_filename, test_content) == 0) {
        printf("File written successfully\n");
    } else {
        printf("Failed to write file\n");
        return 1;
    }

    // Test get_file_size
    long size = get_file_size(test_filename);
    printf("File size: %ld bytes\n", size);

    // Test read_file
    printf("Reading file content...\n");
    char* content = read_file(test_filename);
    if (content) {
        printf("File content: %s\n", content);
        free(content);
    } else {
        printf("Failed to read file\n");
        return 1;
    }

    return 0;
} 
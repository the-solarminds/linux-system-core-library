#include "../include/file_utils.h"

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate buffer
    char* buffer = (char*)malloc(size + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    // Read file content
    size_t bytes_read = fread(buffer, 1, size, file);
    buffer[bytes_read] = '\0';

    fclose(file);
    return buffer;
}

int write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    size_t content_len = strlen(content);
    size_t bytes_written = fwrite(content, 1, content_len, file);

    fclose(file);
    return (bytes_written == content_len) ? 0 : -1;
}

long get_file_size(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
} 
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void create_file(const char *filename);
void write_file(const char *filename, const char *content);
void read_file(const char *filename);
void delete_file(const char *filename);
void seek_file(const char *filename);

#endif

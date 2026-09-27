#ifndef DIRECTORY_OPERATIONS_H
#define DIRECTORY_OPERATIONS_H

void list_directory(const char *path);
void create_directory(const char *dirname);
void remove_directory(const char *dirname);
void change_directory(const char *path);
void show_current_directory(void);

#endif

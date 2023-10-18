#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, int old_size, int new_size);
int _strncmp(char *str_unknown_size, char *str_known_size, int n);
char *_strdup(char *str);
char** tokenizeline(char* input, char* delimiters);
int execute_path(char **input_array, char **argv, char *path);
int access_ok(char **paths);
int exec_cmd(char **paths, char **argv,char **tokenized_input);
char *get_path(void);
int is_path(char *input);
int execute(char **token_array ,char **argv);
int free_array(char **array_ptr);
char *readline(void);
char *strcpy_path(char *dest, char *src, char *user_input);
char *strdup_path(char *str, char *user_input);
char** tokenize_path(char *fullpath, char*user_input);

#endif

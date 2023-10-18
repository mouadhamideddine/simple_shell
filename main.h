#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* External Variable */
extern char **environ;

/* Function Prototypes */
int iswhite(char c);
int strlen_forpath(char *user_input);
int free_array(char **array);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *str_unknown_size, char *str_known_size, int n);
char *strcpy_path(char *destination, char *source, char *userinput);
char *strdup_path(char *str, char *user_input);
char *remove_PATH(char *firsttoken);
void print2DArray(char ***arr);
char **tokenize_path(char *fullpath, char *user_input);
int is_path(char *input);
char *get_path(void);
char *readline(void);
int execute(char **token_array, char **argv);
char **tokenizeline(char *input, char *delimiters);
int execute_path(char **input_array, char **argv, char *path);
int access_ok(char **paths);
int exec_cmd(char **paths, char **argv, char **tokenized_input);

#endif /* MAIN_H */

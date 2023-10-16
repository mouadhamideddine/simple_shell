#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, int old_size, int new_size);
char *_strdup(char *str);
char** tokenizeline(char* input, char* delimiters);
//int execute(char **token_array);
int execute(char **token_array ,char **argv);
int free_array(char **array_ptr);
char *readline(void);

#endif

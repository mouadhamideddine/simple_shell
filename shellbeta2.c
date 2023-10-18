#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int iswhite(char c) 
{
    if (c == ' ' || c == '\t' || c == '\n')
    {
        return(-1);
    }
    return(0);
}

int strlen_forpath(char *user_input)
{
    int i = 0;
    int length = 0;
    if (!user_input)
    {
        perror("!user_input strlen_forpath");
    }
    while(user_input[i] && iswhite(user_input[i]) == -1)
    {
        i++;
    }
    while(user_input[i] && iswhite(user_input[i]) == 0)
    {
        length++;
        i++;
    }
    return(length);
}
int free_array(char **array)
{
    int i = 0;

    if (array == NULL)
    {
        return (0);
    }

    while(array[i])
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    free(array);
    array = NULL;
    return (0);
}
/**
 * _strlen - calculate str length
 * @s : string
 * Return: int
 */
int _strlen(char *s)
{
	int longi = 0;

	while (s[longi] != '\0')
	{
		longi++;
	}

	return (longi);
}
/**
 * _strcpy - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 * _strdup - strdup
 * @str : string
 * Return: Pointer to char
 */
char *_strdup(char *str)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + 1;
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
		return (NULL);
	}

	_strcpy(dupl, str);
	return (dupl);
}

int _strncmp(char *str_unknown_size, char *str_known_size, int n)
{
    int i = 0;

    if(!str_known_size || !str_unknown_size)
    {
        perror("_STRNCMP ERROR");
        return (1);
    }
    if(_strlen(str_unknown_size) < n)
    {
        perror("_STRNCMP n > str_unkonw_size");
        return (1);
    }
    while(str_unknown_size[i] != '\0' && n > 0)
    {
        n--;
        if(str_known_size[i] != str_unknown_size[i])
        {
            return(-1); /*difference*/
        }
        i++;
    }
    return (0); /*match*/
}
/**
 * strcpy_path - copy string
 * @dest : destination
 * @src : source
 * Return: Pointer to str
 */
char *strcpy_path(char *destination, char *source, char *userinput)
{
    int i_dest = 0;
    int i_userinput = 0;
    int i_source = 0;

    while(source[i_source])
    {
        destination[i_dest] = source[i_source];
        i_source++;
        i_dest++;
    }
    destination[i_dest] = '/';
    i_dest++;
    while(userinput[i_userinput] && iswhite(userinput[i_userinput] == -1))
    {
        i_userinput++;
    }
    while(userinput[i_userinput] && iswhite(userinput[i_userinput])  == 0)
    {
        destination[i_dest] = userinput[i_userinput];
        i_userinput++;
        i_dest++;
    }
    destination[i_dest] = '\0';
    return(destination);
}
/**
 * strdup_path - strdup
 * @str : string
 * Return: Pointer to char
 */
char *strdup_path(char *str, char *user_input)
{
	int size = 0;
	char *dupl = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	size = _strlen(str) + strlen_forpath(user_input) + 2; /*+1 only not +2*/
	dupl = malloc(size * sizeof(char));

	if (dupl == NULL)
	{
        free(dupl);
		return (NULL);
	}
	strcpy_path(dupl, str, user_input);
	return (dupl);
}
char *remove_PATH(char *firsttoken)
{
    return (firsttoken+5);
}
void print2DArray(char*** arr) {
    int row = 0;
    while (arr[row] != NULL) {
        int col = 0;
        while (arr[row][col] != NULL) {
            printf("2D%s \n", arr[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
}
char** tokenize_path(char *fullpath, char*user_input)
{
    char **tokenized_fullpath = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;

    if (fullpath == NULL)
    {
        return(NULL);
    }
    
    path_copy = _strdup(fullpath);
    token = strtok(path_copy, ":");
    
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, ":");
    }
    free(path_copy);
    path_copy = NULL;
    tokenized_fullpath = malloc(sizeof(char *) * (count_token + 1)); /* for NULL*/
    if (tokenized_fullpath == NULL)
    {
        return(NULL);
    }
    path_copy = _strdup(fullpath);
    token = strtok(path_copy, ":");
    token = remove_PATH(token);
    while (token != NULL)
    {
        tokenized_fullpath[i] = strdup_path(token, user_input);
        token = strtok(NULL, ":");
        i++;
    }
    tokenized_fullpath[i] = NULL;
    free(path_copy);
    path_copy = NULL;
    /*free(fullpath); reason it's environ[i]*/
    /*fullpath = NULL; reason it's environ[i]*/
    return (tokenized_fullpath); /*a tokenized full path ready for access*/
} 
int is_path(char *input)
{
    int i = 0;
    if (!input)
    {
        return (-1);/*invalid input*/
    }
    while(input[i])
    {
        if(input[i] == '\\' || (input[i] == '/'))
        {
            return (1); /*path*/
        }
        i++;
    }
    return(0); /*not path*/
}
char *get_path(void)
{
    char path_indic[] = "PATH=";
    int i = 0;
    
    while(environ[i])
    {
        if(_strncmp(environ[i],path_indic, 5) == 0)
        {
            return(environ[i]);
        }
        i++;
    }
    return(NULL);
}
char *readline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    }
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        free(line);
        return(NULL);
    }
    return(line);
}



int execute(char **token_array, char **argv)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("FORK ERROR");
        exit(-1);
    }
    else if (pid == 0)
    {
        if(execve(token_array[0], token_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(token_array);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (WEXITSTATUS(status));
}
char** tokenizeline(char* input, char* delimiters)
{
    char **tokenized_input = NULL;
    char *str_copy = NULL;
    char *token = NULL;
    int count_token = 0;
    int i = 0;

    if (input == NULL)
    {
        return(NULL);
    }
    
    str_copy = _strdup(input);
    token = strtok(str_copy, delimiters);
    while(token != NULL)
    {
        count_token++;
        token = strtok(NULL, delimiters);
    }
    free(str_copy);
    str_copy = NULL;
    tokenized_input = malloc(sizeof(char *) * (count_token + 1)); /*removed the +1 but add again*/
    if (tokenized_input == NULL)
    {
        free(input);
        return(NULL);
    }
    token = strtok(input, delimiters);
    while (token != NULL)
    {
        tokenized_input[i] = _strdup(token);
        token = strtok(NULL, delimiters);
        i++;
    }
    tokenized_input[i] = NULL;
    free(input);
    input = NULL;
    return (tokenized_input);
} 
int execute_path(char **input_array, char **argv, char *path)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("FORK ERROR");
        exit(-1);
    }
    else if (pid == 0)
    {
        if(execve(path, input_array, environ) == -1)
        {
            perror(argv[0]);
            free_array(input_array);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (WEXITSTATUS(status));
}

int access_ok(char **paths)
{
    int i = 0;
    int permission;

    if(!paths)
    {
        perror("NO PATH");
        return(-1);
    }

    while(paths[i])
    {
        permission = access(paths[i], X_OK);
        if(permission == 0)
        {
            return(i); 
        }
        else
        {
            ;
        }
        i++;
    }
    return(-2);
}
int exec_cmd(char **paths, char **argv,char **tokenized_input)
{
    int index;
    index = access_ok(paths);
    if(index >= 0)
    {
        execute_path(tokenized_input, argv, paths[index]);
    }
    else if(index < 0)
    {
        return(-1);
    }

    return(0); /*success*/
}


int main(int ac, char **argv)
{
	char delimiters[] = {' ', '\t', '\n', '\0'};
	char **tokenized_input = NULL;
    char **tokenized_path = NULL;
	int status = 0, path_token;
    char *path = NULL;
    char *input = NULL;
    (void)ac;
    
	while (1)
	{
		input = readline();
		if (input == NULL)
		{
			if(isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return(status);
		}
        path_token = is_path(input);
        if(path_token == 1)
        {
            tokenized_input = tokenizeline(input, delimiters);
            execute(tokenized_input, argv);
            free_array(tokenized_input);
            tokenized_input = NULL;
        }
        else if(path_token == 0)
        {
            path = get_path();
            tokenized_path = tokenize_path(path,input);
            tokenized_input = tokenizeline(input, delimiters);
            exec_cmd(tokenized_path, argv,tokenized_input);
            free_array(tokenized_input);
            free_array(tokenized_path);
        }		
	}
	return (status);
}
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
    int leading_whitespace = 0;
    if (!user_input)
    {
        perror("!user_input strlen_forpath");
    }
    while(user_input[i] && iswhite(user_input[i]) == -1)
    {
        i++;
    }
    while(user_input[i] && iswhite(user_input[i] == 0))
    {
        length++;
        i++;
    }
    return(length);
}
char *strcpy_path(char *destination, char *source, char *userinput)
{
    int i_dest = 0;
    int i_userinput = 0;
    int i_source = 0;
    int token = 0;

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
/*
back up*/
/*
char *strcpy_path(char *dest, char *src, char *user_input)
{
	int l = 0;
	int x = 0;
    int i = 0;

	while (src[l] != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l++] = '/';
    while(user_input[i])
    {
        dest[l++] = user_input[i];
        i++;
    }
    dest[l++] = '\0';
	return (dest);
}*/
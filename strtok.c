#include"shell.h"
char **split_line(char *input_line)
{
    char *token = NULL, *tmp = NULL ,DELIM[]=" \t\n";
    char **tokens = NULL;
    int token_count = 0; int i = 0;

    if (!input_line)
        return NULL;
    tmp = strdup(input_line); /*Create a duplicate to avoid modifying the input*/
    token = strtok(tmp, DELIM);
    if (!token)
	{
		free(input_line);
		free(tmp);
		return(NULL);
	}
   while (token)
   {
        token_count++;
        token = strtok(NULL, DELIM);
    }
     free(tmp);

   tokens = (char **)malloc( (token_count + 1) * sizeof(char *));
    if (!tokens) {
      
        free(input_line);
        return(NULL);
    }

    token = strtok(input_line,DELIM); /* Reset tokenization on the original input*/
    
    while (token) {
        tokens[i] = strdup(token);
	i++;
	token =strtok(NULL,DELIM);
    }
         free(input_line);
	tokens[i] = NULL; /*Null-terminate the array*/
	return tokens;
    }

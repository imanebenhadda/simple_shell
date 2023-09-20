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
    while (token) {
        token_count++;
        token = strtok(NULL, DELIM);
    }
     free(tmp);

   tokens = (char **)realloc(tokens, (token_count + 1) * sizeof(char *));
    if (!tokens) {
      
        free(input_line);
        return(NULL);
    }

    token = strtok(input_line,DELIM); /* Reset tokenization on the original input*/
    
    while (token) {
        tokens[i] = strdup(token);
        if (!tokens[i]) {
           
            free(input_line);
            free(tokens);
            return(NULL);
        }
        i++;
        token = strtok(NULL,DELIM);
        free(input_line);

    }
    free(token);

    free(tmp),tmp=NULL; /* Free the temporary duplicate*/
    tokens[i] = NULL; /*Null-terminate the array*/
    free(tokens);
    return tokens;
}



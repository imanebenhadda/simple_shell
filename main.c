#include "shell.h"

int main(int ac, char **argv)
{    
        char *command = NULL;
        char **tokens = NULL;
        int status = 0;
        int i=0;
        (void)ac; /* Argument count */
        
        for (;;) {
                command = read_command();
                if (command == NULL) /* Ctrl+D */ {
                        if (isatty(STDIN_FILENO)) {
                                write(STDOUT_FILENO, "\n", 1);
                                
                        }
                        
                      return (status);
                      
                }
                tokens = split_line(command);
                if (tokens == NULL){
                free(command);}
                    continue;
                
               status = _execute(tokens, argv);
                for (i = 0; tokens[i]; i++){
                free(tokens[i]), tokens[i] = NULL;}
                 free(tokens);
               
                free(command);
                command = NULL; /* Added to fix memory leak */
                
        }
        
       

        return (0); 
}

#include "shell.h"

int main(int ac, char **argv)
{    
        char *command = NULL;
        char **tokens = NULL;
        int status = 0;
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
                    continue;
                }
                
               status = _execute(tokens, argv);
                
                
        }
        
       

        return (0); 
}

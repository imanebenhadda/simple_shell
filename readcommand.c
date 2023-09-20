#include"shell.h"

 

char *read_command(void)

{

        char *command = NULL;

        size_t len = 0;

        ssize_t n;

 

        if (isatty(STDIN_FILENO)) {

                putchar('$'); /*Display "$" if stdin is interactive*/

                putchar(' ');

        }

        n = getline(&command, &len, stdin);

 

        if (n == -1) {

                free(command);

                return (NULL);

        }

       

 

        return(command);

}

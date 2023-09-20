#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
extern char **environ;
int _execute(char **tokens, char **argv);
char **split_line(char *input_line);
char *read_command(void);
/*
char *_strdup(const char *str);
int _strcmp(char *s1, char*s2);
int _strlen(char *s);
char*_strcat(char *dest,char *src);
char*_strcpy(char *dest ,char *src);*/






#endif

/*************************************************************************
	> File Name: 23.pointer.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 21:56:24 2020
 ************************************************************************/

#include<stdio.h>

void output(int argc, char *argv[], char **env){
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i , argv[i]);
    }
    for (int i = 0; env[i]; i++){
        printf("env[%d] = %s\n", i , env[i]);
    }
    return;
}


int main(int argc, char *argv[], char **env){
    output(argc,argv, env);

    return 0; 
}

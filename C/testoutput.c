/*************************************************************************
	> File Name: testoutput.c
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 13:31:48 2020
 ************************************************************************/

#include<stdio.h>


void output(int argc, char *argv[], char *env[]){
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
        }
    for (int i = 0; env[i]; i++){
        printf("%s\n", env[i]);
    }
    return ;
}

int main (int argc, char *argv[], char *env[]){


    output(argc, argv, env);
    return 0;

}

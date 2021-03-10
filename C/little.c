/*************************************************************************
	> File Name: little.c
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 12:06:57 2020
 ************************************************************************/

#include<stdio.h>

int is_little(){
    static int num = 10;
    return ((char *)(&num))[1];
}

int main(){
    printf("%d\n",is_little());
    return 0;
}

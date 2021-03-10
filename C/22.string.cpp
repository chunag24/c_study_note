/*************************************************************************
	> File Name: 22.string.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 19:33:13 2020
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(){
    char str[11] = {0};
    int n;
    while(~scanf("%d", &n)){
        sprintf(str, "%x", n);
        printf("%s has %lu digits", str, strlen(str));
    }
    return 0;

}

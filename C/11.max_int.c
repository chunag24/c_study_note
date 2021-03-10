/*************************************************************************
	> File Name: 11.max_int.c
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Dec 10:24:18 2020
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h>


int max_int(int n, ...){
    int min = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while(n--)
    {
        int temp = va_arg(arg, int);
        if(temp > min) min = temp;
    }
    va_end(arg);
    return min;
}

int main(){
    printf("%d \n", max_int(3, 1, 2, 5));
    return 0;
}

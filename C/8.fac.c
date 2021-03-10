/*************************************************************************
	> File Name: 8.fac.c
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Dec 12:51:23 2020
 ************************************************************************/

#include<stdio.h>

int fac (int n){
    if ( n == 0 ) return 1;
    if ( n == 1 ) return 1;
    return n * fac( n - 1 );
}

int main(){
    int n;
    while(~scanf ("%d", &n)){
        printf("fac(n) == %d\n",fac(n));
    }
    printf("hello world\n");
    return 0;
}

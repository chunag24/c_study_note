/*************************************************************************
	> File Name: 14.prime.c
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Nov 12:23:36 2020
 ************************************************************************/

#include<stdio.h>

#define max_n 100

int prime[max_n + 5];

void init(){
    for ( int i = 2;  i <= max_n; i++){

        if(prime[i] == 0){
            printf("++prime[0] is %d when i is %d\n", ++prime[0], i );
            printf("prime[%d] is set to %d\n ", prime[0], i);
            prime[prime[0]] = i;
        }        

        for (int j = 1; j <= prime[0]; j++){
            if (i * prime[j] > max_n) break;
            prime[prime[j] * i] = 1;
            printf("prime(prime[%d] * %d has been marked 1)\n", j, i);
            if (i % prime[j] == 0) break;
        }
    }
}



int main(){
    init ();
    return 0;
}

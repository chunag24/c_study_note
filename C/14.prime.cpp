/*************************************************************************
	> File Name: 14.prime.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 16:41:55 2020
 ************************************************************************/

#include<stdio.h>
#define max_n 100
int prime[max_n + 5];

void init (){
    for (int i = 2; i <= max_n; i++){
        if(prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++){
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main(){
    init();
    for (int i = 1; i <= prime[0]; i++){
        printf("%d\n", prime[i]);
    }
    return 0;
}

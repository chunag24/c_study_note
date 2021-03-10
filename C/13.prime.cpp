/*************************************************************************
	> File Name: 13.prime.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 15:28:57 2020
 ************************************************************************/


#include<stdio.h>

#define max_n 100

int prime[max_n + 5];

void init(){
    for (int i = 2; i <= max_n; i++){
        if(prime[i]) continue;
        //if it is a prime number 
        ++prime[0];//this is the count of all the prime number
        prime[prime[0]] = i;
        for( int j = 2 * i; j <= max_n; j += i ){
           prime[j] = 1;
        }
    }
    return ;
}

int main(){
    init();
    for (int i = 1; i <= prime[0]; i++){
        printf("%d\n", prime[i]);
    }
    return 0;

    for (int i = 2; i <= max_n; i++){
        if(prime[i]) continue;
        printf("%d\n",i);
    }
    return 0;
}

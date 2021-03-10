/*************************************************************************
	> File Name: test4.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 19:59:39 2020
 ************************************************************************/

#include<stdio.h>

//Given 2 number m and n
//Display all the prime number 
//if no prime number, print 0


int prime[1000005];

void isPrime(int m, int n){
    int temp;
/*    if (m < n){
        temp = n;
        n = m;
        m = temp;
    }*/
    for (int i = 2; i <= n; i++){
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = 2 * i; j <= n ; j += i){
            prime[j] = 1;
        }
    }
    return;
}
void swap(int &a, int &b){
    int temp;
    if (a > b){
        temp = b;
         b = a;
         a = temp;
    } 
    return ;
}

int main(){
    int m, n;

    scanf("%d%d", &m, &n);
    swap(m, n);
    isPrime(m, n);
    for(int i = 1; i <= prime[0]; i++){
        if(prime[i] >= m){
            printf("%d\n", prime[i]);
       
        }           
    }

    return 0;
}

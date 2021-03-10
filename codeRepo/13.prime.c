/*************************************************************************
	> File Name: 13.prime.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 22:42:28 2020
 ************************************************************************/

#include<stdio.h>

#define max_n 100

int prime[max_n + 5];
void init (){
    for (int i = 2; i < max_n ; i++){
        if (prime[i] == 0){
            printf("number is %d\n",++prime[0]);
            prime[prime[0]] = i;
            for (int j = i * 2; j <= max_n; j += i){
                prime[j] = 1;//mark as not a composite number
            }
        }
        printf("prime[0] is %d\n", prime[0]);
    }
    
}

int main (){
    init();
    for(int i = 1; i < prime[0]; i++){
        printf("%d\n",prime[i]);
    }
    return 0;
}

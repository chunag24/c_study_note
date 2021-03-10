/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 21:39:53 2020
 ************************************************************************/

#include<stdio.h>

int prime[20005];

void init(){
    for(int i = 2; i <= 20000; i++){
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for(int j = 2 * i; j <= 20000; j += i){
            prime[j] = i;
        }
    }
    return;
}


void func(int n, int &n1, int &n2, int &n3){
    init();
    for(int i = 1; i <= prime[0]; i++){
        for (int j = 1; j <= prime[0]; j++){
            for (int k = 1; k<= prime[0]; k++){
                if (prime[i] + prime[j] + prime[k] == n){
                    printf("%d %d %d\n", prime[i], prime[j], prime[k]);
                    return;
                    
                    }
            }
        }
    }
    return ;
}

int main(){
    int n, n1, n2, n3;
    scanf("%d", &n);
    func(n, n1, n2, n3);

    return 0;
}


/*************************************************************************
	> File Name: test2.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 20:57:16 2020
 ************************************************************************/

#include<stdio.h>

long long Triangle(long long n){
    return n * (n + 1) / 2;
}
long long Pentagonal(long long n){
    return n * (3 * n - 1) / 2;
}
long long Hexagonal(long long n){
    return n * ( 2 * n - 1 );
}

long long binary_search(long long (*num) (long long), long long n, long long x){
    long long head = 0, tail = n * 3, mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        if (num(mid) == x ) return mid;
        if (num(mid) < x ) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}


int main(){
    int n;
    scanf("%d", &n);
    long long val = Hexagonal(n);
    if (binary_search(Triangle, val, val) == -1){
        printf("NO\n");
        return 0;
    }
    if (binary_search(Pentagonal, val, val) == -1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}

/*************************************************************************
	> File Name: EP45.C
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Dec 21:55:24 2020
 ************************************************************************/

#include<stdio.h>

typedef long long int1;

int1 Triangle(int1 n){
    return n * (n + 1) / 2;
}

int1 Pentagonal (int1 n){
    return n * (3 * n- 1) / 2;

}

int1 Hexagonal( int1  n ){
    return n * (2 * n - 1);
}

int1 binary_search(int1 (*num)(int1), int1 n, int1 x){
    int1 head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if (num(mid) < 0) printf("error\n");
        if (num(mid) == x) return mid;
        if (num(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1; 
}

int main(){
    int n = 285;
    while (1){
        n++;
        int1 val = Triangle(n);
        if(binary_search(Pentagonal, val, val) == -1) continue;
        if(binary_search(Hexagonal, val, val) == -1) continue;
        printf("%lld\n", val);
        break;

    }
    return 0;
}

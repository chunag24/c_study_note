/*************************************************************************
	> File Name: 9.gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Dec 22:37:48 2020
 ************************************************************************/
#include<stdio.h>


using namespace std;
int gcd(int a, int b){
   // if (b == 0) return a;
   // return gcd(b, a % b);
    return (b ? gcd(b, a % b) : a);
}


int main(){
    int a, b;
    while(~scanf("%d%d" , &a, &b)){
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }
    return 0;
}

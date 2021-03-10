/*************************************************************************
	> File Name: 16.my_sqrt.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 18:11:49 2020
 ************************************************************************/

#include<stdio.h>

double sqrt1(double x){
    return x * x;
}

double binary_search(double (*func)(double), double n){

    double min = 0, max = n, mid;
    #define EPLS 1e-6
    while(max - min > EPLS){
        mid = (min + max) / 2.0 ;
        if (n < 1) max = 1.0;
        if (func(mid) < n) min = mid;
        else max = mid;
    }
    #undef EPLS 
    return min;

}


int main(){

    double n;
    while(~scanf("%lf", &n)){
        printf("sqrt1(%lf) = %g\n", n, binary_search(sqrt1, n));
    }
    return 0;
}

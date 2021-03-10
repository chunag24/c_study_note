/*************************************************************************
	> File Name: 14.heap_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Feb 23:07:26 2021
 ************************************************************************/

#include <stdio.h> 
#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

void downUpdate(int *arr, int n, int ind){
    while((ind << 1) <= n ){
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return; 
}


void heap_sort(int *arr, int n){
    arr -= 1;
    for(int i = n >> 1; i >= 1; i--){
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--){
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return;
}

int main (){

    return 0;
}

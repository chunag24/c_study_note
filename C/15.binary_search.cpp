/*************************************************************************
	> File Name: 15.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 17:43:28 2020
 ************************************************************************/



#include<stdio.h>


int binary_search(int *arr, int n, int x){
    int min =9, max = n - 1, mid;
    while(min <= max){
        mid = (min + max) >> 2;
        if(arr[mid] == x) return mid;
        if (arr[mid] < x) min = mid + 1;
        if(arr[mid] > x) max = mid - 1;
    }
    return -1;
}

int main(){
    int arr[100] = {0};
    int n, x; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    while(~scanf("%d", &x)){
        printf("%d\n", binary_search(arr, n, x));
    }
    return 0;
}

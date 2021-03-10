/*************************************************************************
	> File Name: 11.binary_serach.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Feb 16:08:33 2021
 ************************************************************************/



#include <stdio.h>

#define P(func){\
    printf("%s = %d\n", #func, func);\
}


int binary_search(int *arr, int n, int x){
    int head = 0, tail = n - 1, mid;
    while( head <= tail ){
        mid = (head + tail ) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//1111111111100000000
int binary_search1(int *arr, int n, int x){
    int head = 0, tail = n - 1, mid; 
    while (head < tail){
        mid = (head + tail + 1) >> 1;
        if ( arr[mid] == x) head = mid; 
        else tail = mid - 1;
    }
    return head == -1 ? -1 : head;
}

//00000000000111111111
int binary_search2(int *arr, int n, int x){
    int head = 0, tail = n, mid;
    while(head < tail){
        mid = (head + tail) >> 1;
        if (arr[mid] == x) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main (){
    int arr1[10] = {1,3,5,7,9,11,13,17, 19, 21};
    int arr2[10] = {1,1,1,1,0,0,0,0,0,0};
    int arr3[10] = {0,0,0,0,1,1,1,1,1,1};
    P(binary_search(arr1,10,7));
    P(binary_search1(arr2,10,1));
    P(binary_search2(arr3,10,1));
    return 0;
}

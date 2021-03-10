/*************************************************************************
	> File Name: 9.stable_rot.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Feb 16:42:50 2021
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 


#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b;\
    b= __temp;\
}

#define TEST(arr, n, func, args...){\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s= ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}


void insert_sort(int *num, int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--){
            swap(num[j], num[j - 1]);
        }
    }
    return; 
}

void bubble_sort(int *num, int n){
    int times = 1;
    for (int i = 1; i < n && times; i++){
        times = 0;
        for (int j = 0; j < n - i; j++){
            if (num[j] <= num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return; 
}

void merge_sort(int *num, int l, int r){
    if (r - l <= 1){
        if (r - l == l && num[r] < num[l]){
            swap(num[r], num[l]);
        }
        return;
    } 
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *) malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r){
        if ( p2 > r || (p1 <= mid && num[p1] <= num[p2]) ){
            temp[k++] = num[p1++];
        }else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
    
}


void randint(int *arr, int n){
    while (n--) arr[n] = rand() % 100;
    return;
}

void output(int *arr, int n){
    printf("[");
    for (int i = 0; i < n; i++){
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return;
}
int main(){
    srand(time(0));
    #define MAX_N 20 
    int arr[MAX_N];
    randint(arr, MAX_N);
    TEST(arr, MAX_N, insert_sort, num, MAX_N);
    TEST(arr, MAX_N, bubble_sort, num, MAX_N);
    TEST(arr, MAX_N, merge_sort, num, 0, MAX_N - 1);
    #undef MAX_N
    return 0;
}

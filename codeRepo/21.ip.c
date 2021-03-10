/*************************************************************************
	> File Name: 21.ip.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 13:33:04 2020
 ************************************************************************/

#include<stdio.h>


union IP{
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
    unsigned int num;
};
int is_small(){
    static int a = 1;
    return ((char *)(&a))[0];
}

int main(){
    printf("%d",is_small());
    union IP p;
    char str[100] = {0};
    int arr[4];
    while(~scanf("%s",str)){
        sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3 );
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];
        printf("%u\n",p.num);//%u is unsigned integar
    }
    
    return 0;
}

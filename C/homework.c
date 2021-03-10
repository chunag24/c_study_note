/*************************************************************************
	> File Name: homework.c
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 14:26:14 2020
 ************************************************************************/

#include<stdio.h>
#define P(func){\
    printf("%s = %d\n", #func, func);\
}

struct Data{
    int x, y;
};

int main (){

    struct Data a[2];
    struct Data *p = a;
    a[0].x = 0, a[0].y =0;
    a[1].x = 1, a[1].y =1;
    
    P(a[1].x);
    P( (*(a + 1)).x);
    P((a + 1)->x);
    P(p[1].x); 
    P((*p)[1].x);
    P((*(*p + 1)).x);
    return 0;
}


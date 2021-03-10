/*************************************************************************
	> File Name: 22.Data.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Nov 15:08:50 2020
 ************************************************************************/

#include<stdio.h>
#define P(func) {\
    printf("%s = %d \n", #func, func);\
}
struct Data{
    int x, y;

};

int main () {
    struct Data a[2];
    struct Data *p =a ;
    a[0].x = a[0].y = 0;
    a[1].x = a[1].y = 1;

    P(a[1].x);
    P((*(a+1)).x);
    P((a + 1) -> x);
    P((&(*(a + 1)))->x);
    P( (&p[1])->x);
    P( ( p + 1) -> x  );
    P( p[1].x );
    P((&(p[0]) + 1)->x  );
    P((*((&p[0]) + 1)).x);
    return 0;
}

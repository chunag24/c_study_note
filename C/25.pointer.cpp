/*************************************************************************
	> File Name: 25.pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 21 Dec 13:10:51 2020
 ************************************************************************/

#include<stdio.h>

#define offset1(T, a)({\
    T temp;\
   (char *)(&temp.a) -(char *)(&temp);\
})
//Save memory
#define offset(T, a) ((long)(&((T *)(NULL))->a)) 

struct Data{
    int a;
    double b;
    char c;
};

int main(){
        
    int num = 0x0626365;
    printf("%s\n",(char *)(&num));
   
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));


    return 0;
}

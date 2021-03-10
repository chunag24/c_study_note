/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Nov 22:41:24 2020
 ************************************************************************/
// this is just a test
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
typedef struct Vector{
    int *data; 
    int size, length;
} Vec;

//我们需要初始化一个顺序表， 返回值应该是指向顺序表的地址
//int n 代表容量
//定义一个指向顺序表的指针变量 v，通过malloc动态开辟的顺序表的首地址
//第二部分需要给顺序表的各个字段申请存储空间
//连续数据字段的申请
Vec *init(int n){
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
} 

//需要完成顺序表的销毁操作
//先去释放顺序表的数据，
void clear(Vec *v){
    if ( v == NULL ) return ;
    free(v->data);
    free(v);
    return; 
}

int expand(Vec *v){

    int extr_size = v->size;
    //return v->data = (int *)realloc(v->data, sizeof(int)*(v->size + extr_size));
    int *p;
    while(extr_size){
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p) break; // if there is value in p, expand successful
        extr_size >>= 1;
    }
    if (!extr_size) return 0;
    v->data = p;
    v->size += extr_size;
    return 1;
}

int insert(Vec *v, int val, int ind){
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    // Above is to make sure legal insertion
    if (v->length == v->size){
        if(!expand(v)) return 0;//if expand is successful, 0 will be failed, 1 will be succesful
        printf(GREEN("Successfully expanded. The vector size is %d\n"), v->size);
    } 
    for (int i = v->length; i > ind; i--){
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vec *v, int val, int ind){
    if ( v == NULL ) return 0;
    if (ind < 0 || ind > v->length) return 0; 
    for (int i = ind + 1; i < v->length; i++){
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void output(Vec *v){
    if (v == NULL) return;
    printf("Vector : [");
    for (int i = 0; i< v->length; i++){
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return; 
}

int main (){
    srand(time(0));
    #define max_op 20
    Vec *v = init(2);
    for(int i = 0; i < max_op; i++){
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) -1 ;
        int op = rand() % 4;
        switch(op) {
            case 1:
            case 2:
            case 0: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, val, ind));
            }break;
            case 3: {
                printf("erase a iterm at %d from Vector = %d\n", ind, erase(v, val, ind));
            }break;
        }
        output(v);
        printf("\n");
    }
    clear(v);
    #undef max_op

    return 0;
} 

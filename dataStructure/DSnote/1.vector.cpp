/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat  6 Feb 10:27:20 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
//data structure definition
typedef struct Vector {
    int *data;
    int length, size;
} Vec;

Vec *init(int n){
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return v;
}

int expand(Vec *v){
    int extr_size = v->size;
    v->data = (int *) realloc(v->data, sizeof(int) * (v->size + extr_size));
    v->size += extr_size;
    printf("success to expan, the new size = %d\n", v->size);
    return 1;
}


int insert(Vec *v, int ind, int val){
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size ){
        if (!expand(v)) return 0; //expanding the vector 
    }
    for(int i = v->length; i > ind; i--){
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vec *v, int ind){
    if (v == NULL) return 0;
    if ( ind < 0 || ind >= v->length) return 0;
    for(int i = ind + 1; i < v->length; i++){
        v->data[i - 1] = v->data[i];
    }
    v->length-= 1;
    return 1;
}

void output(Vec *v){
    if (v == NULL ) return;
    printf("Vector : [");
    for(int i = 0; i < v->length; i++){
        i && printf(",");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}

void clear(Vec *v){
    if (v == NULL) return;
    free(v->data);
    free(v);
    return; 
}



int main (){
    #define MAX_N 20
    Vec *v = init(1);
    srand(time(0));
    for (int i = 0; i < MAX_N; i++){
        int op, val, ind;
        op = rand() % 4;
        ind = rand() % (v->length + 2) - 1;
        val = rand() % 100;
        switch(op){
            case 2:
            case 1:
            case 0: {
                printf("insert %d at %d = %d\n", val, ind, insert(v, ind, val));
            }break;
            case 3: {
                printf("erase a item at %d = %d\n", ind, erase(v, ind));
            }break;
        }
        output(v), printf("\n");
    }
    clear(v);
    #undef MAX_N 
    return 0;
}

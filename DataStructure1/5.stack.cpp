/*************************************************************************
	> File Name: 5.stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Feb 11:41:12 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

typedef struct Stack{
    int *data;
    int size, top;
}Stack;

Stack *init_stack(int n){
    Stack *s =(Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n; 
    s->top = -1;
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int empty(Stack *s){
    return s->top == -1;
}

int top(Stack *s){
    return s->data[s->top];
}

int expand(Stack *s){
    // how to expand the Stack
    // No need to check whether Stack exists or not 
    int extr_size = s->size;
    int *p;
    while(extr_size){
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extr_size));
        if (p) break;
        extr_size >>= 1; // if the expand could not be completed, reduce the expansion size.
    }
    if (p == NULL ) return 0;
    s->data = p; 
    s->size += extr_size; 
    printf("success to expand! the size = %d\n", s->size);
    return 1;
}

int push(Stack *s, int val){
    if (s == NULL) return 0;
    if (s->top == s->size - 1){
        if (!expand(s)) return 0;
    } // check whether the stack is full. 
    s->top += 1;
    s->data[s->top] = val;
    return 1; 
}

int pop(Stack *s){
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1; 
}

void output(Stack *s){
    if (s == NULL) return;
    printf("Stack : [");
    for(int i = 0; i <= s->top; i++){
        i && printf(",");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return;
}

int main (){
    srand(time(0));
    #define MAX_OP 20
    Stack *s = init_stack(1);
    for(int i = 0; i < MAX_OP; i++){
        int op, val;
        op = rand() % 4;
        val = rand() % 100;
        switch (op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to the Stack = %d\n", val, push(s, val));
            } break;
            case 3:{
                printf("pop %d from the stack= ", top(s));
                printf("%d\n", pop(s));
            }break;

        }
        output(s), printf("\n");
    }
    #undef MAX_OP
    clear(s);

    return 0;
}

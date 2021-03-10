/*************************************************************************
	> File Name: 6.LinkStack.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 19 Feb 10:10:03 2021
 ************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
typedef struct StackNode {
    int data;
    struct StackNode *next;
}StackNode;

typedef struct LinkStack{
    StackNode *top;
    int length; 
}LinkStack;

StackNode *init_node(int val){
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkStack *init_stack(){
    LinkStack *l = (LinkStack *) malloc(sizeof(LinkStack));
    l->top = NULL;
    l->length = 0;
    return l;
}

void clearNode(StackNode *node){
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear(LinkStack *l){
    if ( l == NULL ) return ;
    StackNode *p = l->top, *q;
    while(p != NULL) {
        q = p->next; 
        clearNode(p);
        p = q;
    }
    free(l);
    return ;
}

int push(LinkStack *l, int val){
    if (l == NULL) return 0;
    //之前实现入栈的时候需要判断是否溢出
    //现在不需要判断，使用列表的头插法进行插入
    StackNode *node = init_node(val);
    node->next = l->top;
    l->top = node;
    l->length += 1;
    return 1;
}

int empty(LinkStack *l){
    return l->top == NULL;
}

int pop(LinkStack *l){
    if (l == NULL) return 0;
    if (empty(l)) return 0;
    StackNode *p = l->top;
    l->top = p->next; 
    clearNode(p); 
    l->length --;
    return 1;
}

int Stack_top(LinkStack *l){
    if (empty(l)) return -1;
    return l->top->data;
}

void output(LinkStack *l){
    if ( l == NULL ) return;
    printf("LinkStack(%d) : [", l->length);
    for (StackNode *p = l->top; p; p = p->next){
        p != l->top && printf(",");
        printf("%d", p->data);
    }
    printf("]\n");
}
int main(){
    srand(time(0));
    #define MAX_OP 20
    LinkStack *s = init_stack();
    for (int i = 0; i < MAX_OP; i++){
        int op = rand() % 4;
        int val = rand() % 100;
        switch(op) {
            case 0: 
            case 1:
            case 2:{
                printf("push %d to the LinkStack = %d\n", val, push(s, val));
            }break;
            case 3: {
                printf("pop %d from the LinkStack = ", Stack_top(s));
                printf("%d\n", pop(s));
            }break;
        }
        output(s), printf("\n");
    }
    #undef MAX_OP
    clear(s);


    return 0;
}

/*************************************************************************
	> File Name: 2.linkedlist.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Feb 17:50:46 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h> 


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct list {
    Node head; //虚拟头结点
    int length;
} List;

Node *getNewNode(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

List *init_list(){
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_node(Node *node){
    if (node == NULL) return;
    free(node);
    return ;
}

void clear(List *l){
    if (l == NULL) return;
    Node *p = l->head.next, *q;
    while(p){
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l); 
    return ;
}

int insert(List *l, int ind, int val){
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node; 
    l->length += 1;
    return 1 ;
}

int erase(list *l, int ind){
    if(l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void output(){
    if (l == NULL ) return;
     printf("list(%d) : ", l->length);
    for(Node *p = l->head.next; p; p = p->next){
        printf("%d-> ", p->data);
    }
    printf("NULL\n");
    return ;
}


using namespace std;


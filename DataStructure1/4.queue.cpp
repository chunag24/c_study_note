/*************************************************************************
	> File Name: 4.queue.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Feb 12:22:37 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h> 

typedef struct Queue{
    int*data;
    int head, tail;
    int length;
} Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    return q;
}

int push (Queue *q, int val){
    if (q == NULL) return 0;
    if (q->tail == q->length) return 0;
    q->data[q->tail] = val;
    q->tail += 1;
    //q->data[q->tail++] = val;
    return 1;
}

int empty(Queue *q){
    return q->head == q->tail; 
}

int pop(Queue *q){
    if (q== NULL) return 0;
    if(empty(q)) return 0;
    q->head += 1'
    return 1;
}

int front(Queue *q){
    return q-data[q->head];
}

void clear(Queue *q){
    if (q == NULL) return;
    free(q->data);
    free(q);
    return ;
}


int main ()
{
    srand(time(0));
    #define MAX_OP 20
    Queue *q = init(MAX_OP);
    
    return 0;
}

/*************************************************************************
	> File Name: 4.queue2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Feb 22:46:35 2021
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a,32)


typedef struct Queue {
    int *data;
    int head, tail, count;
    int length;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    q->count = 0;
    return q;
}

int empty(Queue *q) {
    return q->count == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int expand(Queue *q){
    int extr_size = q->length;
    int *temp;
    while (extr_size){
        temp = (int *)malloc(sizeof(int) * (q->length + extr_size));
        if (temp) break;
        extr_size >>= 1;
    }
    if (temp == NULL) return 0;
    for (int i = q->head, j = 0; j < q->count; j++){
        temp[j] = q->data[(i + j) % q->length];
    }
    free(q->data);
    q->data = temp;
    q->head = 0, q->tail = q->count;
    q->length += extr_size;
    printf(GREEN("expand successfully! the new size = %d\n"), q->length);
    return 1;

  /*  int extr_size = q->length; 
    int *temp;
    while (extr_size) {
        temp = (int *)realloc(q-.data, sizeof(int) * (q->length + extr_size));
        if (temp) break;
        extr_size >> 1;
    }
    if (temp == NULL) return 0;
    q->data = temp;
    q->tail = q->head + q->count;
    q->length += extr_size;
    printf(GREEN("expand successfully! the new size = %d\n"),  q->legnth);
    return 1;
    */
}
int push(Queue *q, int val) {
    if (q == NULL) return 0;
    if (q->count == q->length) {
        if(!expand(q)) return 0; 
    }
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail = 0;
    q->count += 1;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head += 1;
    if (q->head == q->length) q->head = 0;
    q->count -= 1;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return ;
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->count; j++) {
        j && printf(",");
        printf("%d", q->data[(i + j) % q->length]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 30
    Queue *q = init(2);
    for (int i = 0; i < MAX_OP; i++) {
        int op, val;
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                if (!empty(q)) {
                    printf("pop %d from the Queue = ", front(q));
                    printf("%d\n", pop(q));
                }
            } break;
        }
        output(q), printf("\n");
    }
    #undef MAX_OP
    clear(q);
    return 0;
}

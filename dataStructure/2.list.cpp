/*************************************************************************
	> File Name: 2.list.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Nov 21:21:23 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct ListNode{
    int data;
    struct ListNode *next;//指向下一个节点的， struct还不可以省略因为还没生效
}ListNode;

typedef struct List {//整个列表的结构定义
    ListNode head;//虚拟头节点
    int length;//记录列表的长度
}List;

ListNode *getNewNode(int ); // 返回节点的地址
List *getLinkList();//返回整个列表的地址
void clear_node(ListNode *);//销毁节点的操作
void clear(List *);
int insert(List *, int, int); 
int erase(List *, int);
void output(List *);

int main(){
    srand(time(0));
    #define max_op 20
    List *l = getLinkList();
    for (int i = 0; i < max_op; i++){
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("inser %d at %d to List = %d\n",val, ind, insert(l, ind, val));
            }break;
            case 3:{
                printf("Erase a iterm at %d from List = %d\n", ind, erase(l, ind));
            }break;
        }
        output(l), printf("\n");
    }
    #undef max_op
    clear(l);

    return 0;
}
int insert(List *l, int ind, int val){
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p  = &(l->head), *node = getNewNode(val);
    while(ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind){
    if (l == NULL ) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void output(List *l){
    if (l == NULL) return;
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next){
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;

}

ListNode *getNewNode(int val){
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}
List *getLinkList(){
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length  = 0;
    return l;
}
 
void clear_node(ListNode *node){
    if (node == NULL) return;
    free(node);
    return;
}

void clear(List *list){
    if (list == NULL) return;
    ListNode *p = list->head.next, *q;
    while(p){
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(list);
    return;
}


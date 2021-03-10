/*************************************************************************
	> File Name: 8.table_to_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Feb 15:35:00 2021
 ************************************************************************/
#include<stdio.h> 
#include<string.h> 


typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree {
    Node *root;
    int length; 
}Tree;


typedef struct Stack{
    Node **data; // 结点的地址
    int top, size;
}Stack;


Stack *init_stack(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data =  (Node **)malloc(sizeof(Node *));
    s->top = -1;
    s->size = n;
    return s;
}

void clear_stack(Stack *s){
    if (s == NULL) return; 
    free(s->data);
    free(s);
    return ;
}

Node *top(Stack *s){
    return s->data[s->top];
}

int empty(Stack *s){
    return s->top == -1;
}

int push(Stack *s, Node *val){
    if (s == NULL) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s){
    if( s == NULL ) return 0;
    if (empty(s) ) return 0;
    s->top --;
    return 1; 
}

Node *getNewNode(char val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree(){
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

void clear_node(Node *root){
    if(root = NULL) return;
    clear_node(root->lchild);
    clear_node(root->rchild);
    free(root);
    return;
}

void clear_tree(Tree *tree){
    if (tree == NULL) return;
    clear_node(tree->node);
    free(tree);
    return ;
}

Node *build(const char *str, int *node_num){
    Stack *s = init_stack(strlen(str));
    int flag = 0;
    while (str[0]){
        switch (str[0]){
            case '(':
            case ')':
            case ',':
            case ' ':
            default:
                temp = getNewNode(str[0]);
                 if (!empty(s) && flag ==0 ){
                    Top(s)->lchild = temp;        
                 }else if (!empty(s) && flag == 1){

                 }      
        }   
    }
}

int main(){
    char str[10000] = {0};
    scanf("%[^\n]s", str);//字符串包括空格处理
    getchar(); 
    Tree *tree = getNewTree();
    tree->root = build(str，&node_num);
    tree->length = node_num;
    return 0;
}

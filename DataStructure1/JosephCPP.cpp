/*************************************************************************
	> File Name: JosephCPP.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Feb 11:29:22 2021
 ************************************************************************/

#include<iostream>
using namespace std;


template <typename Type> class Node {
public: 
    Type data; 
    Node<type> *next;
    Node(const Type &_data){
        data = _data;
        next = NULL:
    }
};

template <typename Type> class LinkedList{
    private:
        Node<Type> *head;
    public: 
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node<Type> *current_node = head;
        while(current_node !=  NULL){
            Node<Type> *delete_node = current_node;
            current_node = current_node -> next; 
            delete delete_node;
        }
    }
    void insert(Node<Type> *node, int index){
        if (head == NULL){
            if ( index != 0 ){
                return;
            }
            head = node; 
            return;
        }

        if (index == 0){
            node -> next = head;
            head = node;
            return;
        }
        Node<Type> *current_node = head; 
        int count = 0;
        while(current_node->next != NULL && count < index - 1){
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1){
            node->next = current_node->next;
            current_node -> next = node; 
        }
    }

}

int main(){
    LinkedList<int> linkedlist;
    return 0;
}

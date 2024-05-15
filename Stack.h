#ifndef Stack_h
#define Stack_h
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class Stack {
private:
    Node<T> *top;
public:
    Stack(){
        top = NULL;
    }
    void Push( T value){
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    T Pop(){
        Node<T> *temp = top;
        T value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }
    T GetTop()const{
        return top -> data;
    }
    bool IsEmpty()const{
        return top == NULL;
    }

        
};
#endif
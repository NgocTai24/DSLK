#ifndef Queue_h
#define Queue_h
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class Queue {
private:
    Node<T> *tail;
    Node<T> *head;
public:
    Queue(){
        head = NULL;
        tail = NULL;

    }
    void EnQueue(T value) {
        Node<T> *newNode = new Node<T>();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail ->next = newNode;
            tail = newNode;
        }
    }
    T DeQueue(){
        Node<T> *temp = head;
        T value = temp->data;
        head = head->next;
        delete temp;
        if (head == NULL){
            tail = NULL;
        }
        return value;
    }
    T GetFirst()const{
        return head -> data;
    }
    bool IsEmpty()const{
        return head == NULL;
    }       
};
#endif
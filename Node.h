#ifndef Node_h
#define Node_h
template <class T>
struct Node{
    T data;
    Node<T> *next;
};
#endif 
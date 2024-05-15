#ifndef List_h
#define List_h
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }
    // cau tu sao chep 
    List(const List<T> &other) {
        head=NULL;
        tail=NULL;
    Node<T> *p = other.head;
    while (p != NULL) {
        this ->Add(p->data);
        p = p->next;
    }
    }
    // qua tai toan tu gan
    List<T>& operator= (const List<T>& other ){
        if (this != &other){ // kiểm tra tu gán bằng cách so sánh địa chỉ
            this ->Reset(); // xoá nội dung hiện tại
            // sao chép tu danh sách khác
            Node<T> *p = other.head;
            while( p != NULL){
                this ->Add(p ->data);
                p = p ->next;
            }
        }
        return *this; // tra ve tham chieu toi doi tuong hien taicm

    }
    void Add(T value) {
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
    void AddFrist( T value){
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            newNode ->next = head;
            head = newNode;
        }
    }
    void PrintAll() const{
        Node<T> *p = head;
        while (p != NULL) {
            cout << p->data << " ; ";
            p = p->next;
        }
        cout << endl;
    }
    void Update(int pos , T value){
        Node<T> *p = head;
        for(int i = 1; i <= pos - 1; i++){
            p = p ->next;
        }
        p ->data = value;
    }
    void Delate(int pos){
        if (pos == 1){
            Node<T> *t = head;
            head = head ->next;
            if (head == NULL){
                tail = NULL;
            }
            delete t;
        }
        else{
            Node<T> *p = head;
            for (int i = 1; i<= pos -2; i++){
                p = p ->next;
            }
            Node<T> *t = p ->next;
            p ->next  = t ->next;
            if (p ->next == NULL){
                tail = p;
            }
            delete t;
        }
    }
    int GetSize()const {
        int size = 0;
        Node<T> *p = head;
        while (p != NULL) {
            size++;
            p = p->next;
        }
        return size;
    }
    T GetvalueInPos(int pos){
        Node<T> *p = head;
        int count = 1;
        while(p != NULL && count < pos){
            p = p ->next;
            count ++;
        }
        return p ->data;
    }

    void Insert(int pos, T value){
        Node<T> * newNode = new Node<T>();
        newNode ->data = value;
        if (pos == 1){
            newNode ->next = head;
            head = newNode; 
        }
        else{
            Node<T> *p = head;
            for (int i = 1; i<= pos -2; i++){
                p = p ->next;
            }
            newNode ->next = p->next;
            p->next = newNode;
        }
    }
    bool Find(T value)const{
        Node<T> *p = head;
        while(p != NULL){
            if (p ->data == value){
                return true;
            }
            p = p ->next;
        }
        return false;
    }
    void Reset(){
        Node<T> *p = head;
        head = NULL;
        tail = NULL;
        delete p;
    }
    void Swap(int pos1, int pos2){
        Node<T> *p = head, *temp1 = NULL;
        for (int i =1 ; i<= pos1-1; i++){
            temp1 = p; // luc nay temp1 dang ơ truoc vi tri pos1
            p = p ->next;
        }
        Node<T> *q = head, *temp2 = NULL;
        for (int i = 0; i< pos2 -1 ; i++){
            temp2 = q; // luc nay temp2 dang ơ truoc vi tri pos2
            q = q ->next;
        }
        if (temp1 != NULL){
            temp1 ->next = q;
        }else{
            head = q;
        }
        if (temp2 != NULL){
            temp2 ->next = p;
        }else{
            head = p;
        }
        Node<T> *temp = p ->next;
        p ->next = q ->next;
        q->next = temp;
    }
    void Reverse(){
        if (head == NULL || head->next == NULL){
            return;
        }
        Node<T> *truoc = NULL;
        Node<T> *p = head;
        Node<T> *tieptheo = NULL;
        while(p != NULL){
            tieptheo = p ->next;
            p -> next = truoc;
            truoc = p;
            p = tieptheo;
        }
        head = truoc;
    }
};
#endif
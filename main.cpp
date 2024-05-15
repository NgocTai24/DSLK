#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main(){
    // List <int> ds;
    // ds.Add(1);
    // ds.Add(2);
    // ds.Add(3);
    // ds.Add(4);
    // List<int> ds2(ds);
    // ds.Delate(3);
    // ds.PrintAll();
    // ds2.Update(2, 5);
    // ds2.PrintAll();
    // cout<<ds2.GetvalueInPos(2);
    // Stack <int> ds;
    // ds.Push(1);
    // ds.Push(2);
    // ds.Push(3);
    // ds.Push(4);
    // ds.Push(5);
    // cout<<ds.Pos();
    // cout<<endl;
    // cout<<ds.GetTop();
    // cout<<endl;
    // cout<<ds.IsEmpty();
    Queue<int> ds;
    ds.EnQueue(1);
    ds.EnQueue(2);
    ds.EnQueue(3);
    ds.EnQueue(4);
    cout<<ds.DeQueue();
    cout<<ds.DeQueue();
    cout<<endl;
    cout<<ds.GetFirst();
    return 0;
}
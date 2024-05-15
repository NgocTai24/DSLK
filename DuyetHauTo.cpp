#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int main(){
   Stack <int> s;
   string x;
   cout<<"Moi nhap xau ky tu kieu hau to !!: ";
   cin>>x;
   int i = 0;
   while (i < x.length()){
        if (x[i] >= '0' && x[i] <= '9'){
            s.Push(x[i] - '0');
        }
        else{
            if (x[i] == '+'){
                int p1 = s.Pop();
                int p2 = s.Pop();
                s.Push(p1 + p2);
            }
            else if (x[i] == '-'){
                int p1 = s.Pop();
                int p2 = s.Pop();
                if (p1 < p2){
                    s.Push(p2 - p1);
                }
                else{
                    s.Push(p1 -p2);
                }
            }
            else if (x[i] == '*'){
                int p1 = s.Pop();
                int p2 = s.Pop();
                s.Push(p1 * p2);
            }
            else if (x[i] == '/'){
                int p1 = s.Pop();
                int p2 = s.Pop();
                s.Push(p2 / p1 );
            }
        }
        i ++; 
   }
   cout <<" VALUE : "<<s.GetTop()<<"\t";
    return 0;
}
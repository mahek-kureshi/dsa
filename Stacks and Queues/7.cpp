#include<bits/stdc++.h>
using namespace  std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(!s2.empty()){
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int Top(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    int size() {
        return s1.size() + s2.size();
    } 
};

int main(){
Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.Top() << endl;   // 1

    q.pop();

    cout << q.Top() << endl;   // 2

    cout << q.size() << endl;  // 2

    return 0;
}
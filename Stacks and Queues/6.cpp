#include<bits/stdc++.h>
using namespace  std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    }

    void pop(){
        if (s1.empty())
            return;

        s1.pop();
    }
    int Top(){
        if (s1.empty())
            return -1;

        return s1.top();

    }
    int size() {
        return s1.size();
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
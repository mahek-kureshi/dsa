#include<bits/stdc++.h>
using namespace std;

class Queue{
int start = -1;
int end = -1;
int currsize = 0;
int size = 4;
int q[4];

public:

void push(int x){
    if(currsize == size){
        cout<<"Queue overflow \n";
        return;
    }
    if(currsize == 0){
        start = 0;
        end = 0;
    }
    else{
        end = (end + 1) % size;
    }
    q[end] = x;
    currsize++;
}

void pop(){
    if(currsize == 0){
        cout<<"Queue is empty \n";
        return;
    }
    if(currsize == 1){
        start = -1;
        end = -1;
    }
    else{
        start = (start + 1) % size;
    }
    currsize--;
}
int top(){
    if(currsize == 0){
        cout<<"Queue is empty \n";
        return -1;
    }
    else{
        return q[start];
    }
}
int queuesize(){
    return currsize;
}
};

int main(){
    Queue q;
    q.push(3);
    q.push(2);
    q.push(4);

    cout << q.top() << endl;    // 3

    q.pop();
    cout << q.top() << endl;    // 2

    cout << q.queuesize() << endl;   // 2


    return 0;
} 
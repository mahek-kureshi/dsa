#include<bits/stdc++.h>
using namespace std;

class Queue{
    struct Node{
        int data;
        Node * next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };

    Node * start = NULL;
    Node * end = NULL;
    int currsize = 0;

    public:
    void push(int x){
        Node * temp = new Node(x);
        if(currsize==0){
            start = temp;
            end = temp;
        }
        end->next = temp;
        end = temp;
        currsize++;
    }

    void pop(){
        if(currsize == 0){
            cout<<"stack is empty\n";
            return;
        }
        Node * temp = start;
        start = start->next;
        delete temp;
        currsize--;

        if(currsize == 0){
            end = NULL;
        }
    }

    int top(){
        if(currsize == 0){
            cout<<"stack is empty\n";
            return -1;
        }
        return start->data;
    }
        int size() {
        return currsize;
    }

};

int main(){
Queue q;

    q.push(3);
    q.push(2);
    q.push(4);
    q.push(7);

    cout << q.top() << endl;   // 3

    q.pop();

    cout << q.top() << endl;   // 2

    cout << q.size() << endl;  // 3


    return 0;
}
// stack using linked list
#include<bits/stdc++.h>
using namespace std;

class Stack{
    struct Node{
        int data;
        Node * next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };

    Node * topnode = NULL;
    int currsize = 0;

    public:

    void push(int x){
        Node * temp = new Node(x);
        temp->next = topnode;
        topnode = temp;

        currsize++;
    }
    int top(){
        if(currsize == 0){
            cout<<"Stack is empty\n";
            return -1;
        }
        else{
            return topnode->data;
        }
    }
    void pop(){
       if(currsize == 0){
            cout<<"Stack is empty\n";
            return;
        } 
        else{
            Node * temp = topnode;
            topnode = topnode->next;
            delete temp;
            currsize--;
        }
    }
    int size(){
        return currsize;
    }

};

int main(){
    Stack st;

    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);

    cout << st.top() << endl;   // 1

    st.pop();

    cout << st.top() << endl;   // 3

    cout << st.size() << endl;  // 3


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top = -1;
    int st[10];

    public:
    
    void push(int x){
        if(top >= 9){
            cout<<"Stack overflow \n";
            return;
        }
        top = top + 1;
        st[top] = x;
    }

    int Top(){
        if(top == -1){
            cout<<"Stack is empty \n";
            return -1;
        }
        return st[top];
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty \n";
            return;
        }
        top = top -1;
    }
    int size(){
        return top + 1;
    }
};

int main(){
    Stack st;

    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);

    cout<< st.Top() << endl; //1
    st.pop();
    cout<<st.Top()<<endl; //3
    cout<<st.size()<<endl; //3
    return 0;
}
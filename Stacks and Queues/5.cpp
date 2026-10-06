#include<bits/stdc++.h>
using namespace std;

class Stack{
  public:
    queue<int> q;

  
    void push(int x){
        int n = q.size();
        q.push(x);
        for(int i=0; i<n ; i++){
            q.push(q.front()); //q.top = q.front
            q.pop();
        }
    }
    void pop(){
        if (q.empty())
            return;

        q.pop();
    }
    int Top(){
        if (q.empty())
            return -1;

        return q.front();
    }
    int size() {
        return q.size();
    }

};

int main(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.Top() << endl;   // 3

    st.pop();

    cout << st.Top() << endl;   // 2

    cout << st.size() << endl;  // 2


    return 0;
}
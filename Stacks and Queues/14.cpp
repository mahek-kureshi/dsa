// min in stack
#include<bits/stdc++.h>
using namespace std;

//M-1
class st{
    stack<pair<int,int>> st;
    public:
    void push(int val){
        if(st.empty()){
            st.push({val,val});
            
        }
        else{
        st.push({val, min(val,st.top().second)});
        }
    }

    int getMin(){
         return st.top().second;
    }
    
    int top(){
        return st.top().first;
    }

    void pop(){
    st.pop();
    }
};

//M-2
class stt{
    stack<int> st;
     int min;
    public:
    void push(int val){
       
        if(st.empty()){
            st.push(val);
            min = val;
        }
        else{
            if(val >= min){
                st.push(val);
            }
            else{
                int newval = 2*val - min;
                st.push(newval);
                min = val;
            }
        }
    }
    int getMin(){
        if (st.empty())
        {
            return -1;
        }
        return min;
    }

    void pop(){
        if(st.empty()){
            return ;
        }
        // If top is encoded
         // Encoded value means actual top is mini
            if(min > st.top()){
                min = 2*min - st.top();
            }

       st.pop();
    }

    int top(){
         if (st.empty())
        {
            return -1;
        }

        // Encoded value means actual top is mini
        if (st.top() < min)
        {
            return min;
        }

        return st.top();
    }
};

int main(){
    stt s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout<< s.getMin()<<endl; //10
    s.pop();
    cout<< s.top()<<endl; //15
    cout<< s.getMin()<<endl; //12

    return 0;
}
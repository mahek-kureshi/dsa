//infix to postfix conversion
#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    int ans;
    if(c == '^'){
        ans = 3;
    }
    else if(c == '*' || c == '/'){
        ans = 2;
    }
    else if(c == '+' || c == '-'){
        ans = 1;
    }
    else{
        ans = -1;
    }
    return ans;
}

string infix2postfix(string s){
    string ans;
    stack<char> st;
    for(int i=0; i < s.size(); i++){
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){ //if operand
            ans.push_back(s[i]);
        }
        else if( (s[i] == ')')  ){
            while(!st.empty() && st.top() != '(' ){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if( (s[i] == '(') ){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && priority(s[i]) >= priority(st.top())){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top()) ){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    string s = "a+b*(c^d-e)";
    string ans = infix2postfix(s);
    cout<< ans;

    return 0;
}
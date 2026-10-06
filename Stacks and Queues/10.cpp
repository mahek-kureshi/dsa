//infix to prefix
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

// string reverse(string s){   //this can also be used no problem with it
//     int i = 0;
//     int j = s.size()-1;
//     while(i<j){
//         if(s[i] == '(') s[i]=')';
//         else if (s[i] == ')') s[i]='(';
//         swap(s[i],s[j]);
//         i++;
//         j--;
//     }

//     return s;
// }

string reverse(string s)
{
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            s[i] = ')';

        else if(s[i] == ')')
            s[i] = '(';
    }

    return s;
}

string infix2prefix(string s){
    s = reverse(s);
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

    ans = reverse(ans);
    return ans;
}

int main(){
    string s = "(A+B)*C-D+F";
    string ans = infix2prefix(s);
    cout<< ans;
    return 0;
}
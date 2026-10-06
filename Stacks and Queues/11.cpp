//postfix to infix
#include<bits/stdc++.h>
using namespace std;

string postfix2infix(string s){
    stack<string> st;
for(int i=0; i < s.size(); i++){
    if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){ //if operand
        st.push(string(1,s[i]));
    }
    else{ //if operator
        string t1  = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();
        string con = "(" + t2 + s[i] + t1 + ")";
        st.push(con);
    }
}
return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    string ans = postfix2infix(s);
    cout<< ans;

    return 0;
}
//prefix to infix
#include<bits/stdc++.h>
using namespace std;

string prefix2infix(string s){
    stack<string> st;
    int n = s.size();
for(int i = (n-1); i >= 0;i--){
    if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){ //if operand
        st.push(string(1,s[i]));
    }
   else{ //if operator
        string t1  = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();
        string con = "(" + t1 + s[i] + t2 + ")";
        st.push(con);
    }
}
return st.top();
}

int main(){
    string s = "*+PQ-MN";
    string ans = prefix2infix(s);
    cout<< ans;

    return 0;
}
//postfix to prefix and vice versa
#include<bits/stdc++.h>
using namespace std;

string postfix2prefix(string s){
    stack<string> st;
    int n = s.size();
for(int i = 0; i < n;i++){
    if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){ //if operand
        st.push(string(1,s[i]));
    }
   else{ //if operator
        string t1  = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();
        string con = s[i] + t2 + t1;
        st.push(con);
    }
}
return st.top();
}

string prefix2postfix(string s){
    stack<string> st;
    int n = s.size();
for(int i = n-1; i >= 0;i--){
    if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){ //if operand
        st.push(string(1,s[i]));
    }
   else{ //if operator
        string t1  = st.top();
        st.pop();
        string t2 = st.top();
        st.pop();
        string con = t1 + t2 + s[i];
        st.push(con);
    }
}
return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    string ans = postfix2prefix(s);
    cout<< ans<<endl;

    string s1 = "/-AB*+DEF";
    string ans1 = prefix2postfix(s1);
    cout<< ans1;

    return 0;
}
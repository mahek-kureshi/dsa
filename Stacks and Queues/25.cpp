//remove k digits
//num string will be give, remove k no. of digits such that the resultant is smallest no. possible

#include<bits/stdc++.h>
using namespace std;

string ans(string num, int k){
    string ans="";
    int n = num.length();
    stack<char> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && k>0 && (st.top())>(num[i])){
            st.pop();
            k = k-1;
        }
        st.push(num[i]);
    }
        while(k>0 && !st.empty()){
            st.pop();
            k = k-1;
        }
        if(st.empty()){
            return "0";
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        //removing leading zeroes

        int i = 0;

        while(i < ans.size() && ans[i] == '0'){
           i++;
        }  

        ans = ans.substr(i);

        if(ans.empty()){
            return "0";
        }
    
    return ans;
}

int main(){
    string num ="1432219";
    string answer = ans(num,3);
    cout<<answer;
    return 0;
}
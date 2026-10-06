#include<bits/stdc++.h>
using namespace std;

// works only for lowercase letters
//through ascii values

int main(){
    string s;
    cin>> s;

    //precompute
    int hash[26]={0};  //if hash[256] then it will work for all characters
    for (int i=0; i<s.size(); i++){
        hash[s[i]-'a'] ++;   //hash[s[i]] ++; for all characters
    }

    int q;
    cin>> q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;  //cout<<hash[c]<<endl; for all characters
    }
}
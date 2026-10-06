// Make a string pallindrome
// minimum no. of char required to make it pallindrome

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lpsfind(string s){
    vector<int> lps(s.size(),0);
    int pre = 0;
    int suf = 1;
    
    while(suf<s.size()){
        //match
        if(s[pre] == s[suf]){
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        //not match
        else{
            if(pre == 0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }
    return lps[s.size()-1];
}

int mini(string s){
        string rev = s;
       string temp = s + "$";
       reverse(rev.begin(),rev.end());
       temp += rev;
       int n = s.size();
       int p = lpsfind(temp);
       return n-p;
}

int main(){
    string s = "aaaotcaakr";
    cout << "min char req to make it pallindrome is/are : "<< mini(s);
    return 0;
}
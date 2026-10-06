// longest prefix sum
//knuth-morris-pratt algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lps(string s){

    vector<int> lps(256,0);
    int pre =0;
    int suf = 1;

    while( suf < s.size()){

        //match kare toh
        if( s[pre] == s[suf]){
            lps[suf]= pre + 1;
            pre++;
            suf++;
        }
        //match na kare toh
        else{
            if(pre == 0){
                lps[suf] = 0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }

    return lps[s.size()-1];
}

int main(){
    string s = "ABCABDABCABCABD";

    cout<< lps(s);

    return 0;
}
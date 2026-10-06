// circular pattern matching

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void lpsfind(vector<int> lps, string s){  //lps table req for kmp algo
    int pre =0;
    int suf = 1;
    while(suf < s.size()){
        //match
        if( s[pre] == s[suf]){
            lps[suf] = pre +1;
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
}

int kmp(string s, string f){     //to check string matching or not
    vector<int> lps(f.size(),0);
    lpsfind(lps,f);
    int first = 0;
    int second =0;

while( first < s.size() && second < f.size()){
    //match
    if(s[first] == f[second]){
        first++;
        second++;
    }
    //not match
    else{
        if(second == 0){
            first++;
        }
        else{
            second = lps[second-1];
        }
    }
    if(second == f.size()){
        return 1;
    }
}
return -1;

}

int cirp(string s,string f){
    string temp = s + s;
    return kmp(temp,f);
}

int main(){
   string s = "cdefabroaab";
    string f = "abcde";

    cout<< cirp(s,f);
    return 0;
}
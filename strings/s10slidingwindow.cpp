// sliding window protocol
// to find the length of the longest substring without repeating char

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcdecbeadf";


    int i1=0;
    int i2=0;
    int len=0;
    int maxlen = 0;
    vector<bool> ch(256,0);

    for(int i2=0; i2 < s.size(); i2++){

        while(ch[s[i2]]){
            ch[s[i1]]=0;
            i1++;
        }
        ch[s[i2]]=1;
         
        len = i2 - i1 + 1;
        maxlen = max( maxlen, len);
    }

    cout<<maxlen;
    return 0;
}
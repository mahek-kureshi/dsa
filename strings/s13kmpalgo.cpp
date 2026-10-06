// string matching
// brute force approach - naive algo

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void lpsfind(vector<int>&lps,string s){

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
}

int kmp(string haystack, string needle ){
    int m = haystack.size();
    int n = needle.size();

    vector<int> lps(n,0);
    lpsfind(lps, needle);

    int first = 0;
    int second = 0;

    while( first < m){
        //match
        if(haystack[first] == needle[second]){
            first++;
            second++;
        }
        //not match
        else{
            if(second == 0){
                first++;
            }
            else{
                second = lps[second - 1];   //most crucial line in kmp
            }
        }
        if(second == n){
            return first - second;
        }
    }
    
   return -1;
}

int main(){
    string haystack = "onionionson";  // text- t
    string needle = "onions";     // pattern - p

    cout<< kmp(haystack,needle);

    return 0;
}
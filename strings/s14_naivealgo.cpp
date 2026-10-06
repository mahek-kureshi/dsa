// string matching
// brute force approach - naive algo

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int stringMatch(string text, string pattern ){
    int first = 0; // pointer in text
    int second = 0;   // pointer in pattern

   for (int i=0; i< text.size()-pattern.size(); i++){
    first = i;
    second =0;

    while(second < pattern.size()){
        //match
        if(text[first] == pattern[second]){
            first++;
            second++;
        }
        //not match
        else{
            break;
        }

        if(second == pattern.size()){
            return i;  // here i = first -second
        }
        
    }
   }
   return -1;
}

int main(){
    string haystack = "onionionson";  // text- t
    string needle = "onions";     // pattern - p

    cout<< stringMatch(haystack,needle);

    return 0;
}
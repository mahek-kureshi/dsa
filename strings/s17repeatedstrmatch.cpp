//Repeated string match

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void lpsfind(vector<int> lps,string s){   //to find lps table req in kmp algo
    int pre =0;
    int suf =1;
    while(suf < s.size()){
        //match 
        if(s[pre] == s[suf]){
            lps[suf] = pre +1;
            pre++;
            suf++;
        }
        //not match
        else{
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }
}

int kmpsearch(string haystack, string needle){   //kmp algo for string matching or not
    vector<int> lps(needle.size(),0);
    lpsfind(lps,needle);

    int first =0;
    int second =0;

    while(first < haystack.size() && second < needle.size()){
        //match 
        if(haystack[first] == needle[second]){
            first++;
            second++;
        }
        //not match
        else{
            if(second ==0){
                first++;
            }
            else{
                second = lps[second-1];
            }
        }

        if(second == needle.size()){
            return 1;
        }
    }
    return -1;
}
 
int rsm(string a, string b){                           //rsm- repeated string match
    string temp;
    int repeat = 0;  //coz temp is already empty here 
    while(temp.size() < b.size()){
        temp += a;
        repeat++;
    }
    if(kmpsearch(temp,b) == 1){
        return repeat;
    }
    else if(kmpsearch(temp+=a,b) == 1){
        return repeat+1;
    }
    return -1;
};

int main(){
   string a = "abc";
   string b = "cabcabcabca";

   cout << rsm(a,b);
    return 0;
}
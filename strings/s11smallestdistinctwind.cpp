// smallest distinct window- so that sare unique character aa jaye atleast ek baar
// sliding window concept

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int smallest(string s){
    int i1 = 0; 
    int i2 = 0;
    int len = s.size();
    vector<int> count(256,0);
    int diff=0;

    for(int i=0; i<s.size(); i++){  // to see kitne unique char hai in string given
        if(count[s[i]]==0){
             diff++;
        }
        count[s[i]]++;
    }

    for(int i=0; i<256; i++){  // wapis vector count ki sari value ko zero banane ke liye
        count[i]=0;
    }

    while(i2 < s.size()){
        //diff exist kare tab
        while(diff && i2 < s.size())
        {   if(count[s[i2]]==0){
             diff--;
            }
            count[s[i2]]++;
            i2++;
        }

        len = min( len, i2 - i1); //yaha pe i2-i1+1 mhi coz i2++ ho chuka hai 

        //diff ki value 1 na bane
        while(diff != 1){
            count[s[i1]]--;
            if(count[s[i1]]==0) diff++;
            len = min( len, i2 - i1);

            i1++;
        }
    }

    return len;
}

int main(){
    string s = "AABBBCBBAC";

    cout<< smallest(s);

    return 0;
}
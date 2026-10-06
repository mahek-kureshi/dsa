//longest pallindrome substring
#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(string s){
    int left = 0;
    int n = s.length();
    int right = n-1;

    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string lps1(string s){
    int n= s.length();
    string ans = "";
    for(int i=0; i < n; i++){
        for(int j =i+1; j<n; j++){
            string sub = s.substr(i,(j-i+1)); //point to be noted
         if(isPallindrome(sub) && ans.length() < sub.length() ){
            ans = sub;
         }
        }
    }
    return ans;
}

string lps2(string s){

    int n = s.length();
    int start = 0;
    int maxlen = 1;

    for(int i=0; i < n; i++){

        //for odd length
        int left = i;
        int right = i;

        while(s[left] == s[right] && left >= 0 && right < n){
            if(right-left+1 > maxlen){
                maxlen = right-left+1;
                start = left;
            }
            left--;
            right++;
        }

        //for even length
        left = i;
        right = i+1;

        while(s[left] ==s[right] && left >= 0 && right < n){
            if(right-left+1 > maxlen){
                maxlen = right-left+1;
                start = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(start,maxlen);
}

int main(){;

    string s = "babad";
    cout << lps2(s);
    
    return 0;
}
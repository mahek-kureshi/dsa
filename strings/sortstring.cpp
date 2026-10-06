// code to sort a string
// we can sort it using selection, bubble, insertion sort or any other sorting also
// but here we solved with other method, main adv is time complexity is o(n) 

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "edcab";

    vector<int> alpha(26,0);

    for(int i=0; i< s.size(); i++){
        alpha[s[i]-'a']++;
    }

    string ans;
    for(int i=0; i<26; i++){
        char c = 'a'+ i;

        while(alpha[i]){
            ans += c;
            alpha[i]--;
        }
    }

    cout << ans;

    return 0;
}
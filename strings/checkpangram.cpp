// code to check pangram 

#include<bits/stdc++.h>
using namespace std;

int main(){
    string sentence = "the quick brown fox jumps over the lazy dog";
    vector<int> lower(26,0);

    for(int i=0; i < sentence.size(); i++){
        if(sentence[i] >= 'a'){
            lower[sentence[i]-'a']++;
        }
    }

    for(int i=0; i<26; i++){
        if(lower[i] == 0){
            cout<<"not a pangram!";
            return 0;
        }
    }

    cout<<"it is a pangram!"; // pangram-that contains all the alphabets, a to z

    return 0;
}
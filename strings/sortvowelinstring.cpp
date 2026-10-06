// code to sort vowels in a string

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "lEetcOde";
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    //traverse the string, selecting vowels
    for(int i= 0; i<s.size(); i++){
        if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            lower[s[i]-'a']++;
            s[i]='#';
        }
        else if( s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            upper[s[i]-'A']++;
            s[i]='#';
        }
    }

    //sorting them in midans
    string midans;

    for(int i=0; i<26; i++){ //upper
        char temp = 'A' + i;
        while(upper[i]){
            midans += temp;
            upper[i]--;
        }
    }

    for(int i=0; i<26; i++){ //lower
        char temp = 'a' + i;
        while(lower[i]){
            midans += temp;
            lower[i]--;
        }
    }

    //insert vowels at the right position 
    int i = 0; // pointer for s[i]
    int j = 0; //pointer for midans[j]
    while( j < midans.size()){
        if(s[i]=='#'){
            s[i]=midans[j];
            j++;
        }
        i++;
    }

    cout<<s;
    
    return 0;
}
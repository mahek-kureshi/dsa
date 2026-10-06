 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

 int main(){
    string s = "myself2 me1 i4 and3";

    int count=0;
    vector<string> ans(10);
    string temp;

    for(int i=0; i < s.size() ; i++){
    
        if(s[i] == ' '){
            int pos = temp[temp.size() - 1] - '0';  //position of word in a sentence
            temp.pop_back();
            ans[pos] = temp;
            temp.clear();                           // reset for next word
            count++;
        }
        else temp += s[i];
    }
        // for last word
        int pos = temp[temp.size() - 1] - '0';  //position of word in a sentence
            temp.pop_back();
            ans[pos] = temp;
            count++;
            temp.clear();


    //merging the sentence
    for(int i=0; i <= count; i++){
        temp += ans[i];
        temp += " ";
    }
      
    temp.pop_back();
      
    cout <<temp;

    return 0;
 }
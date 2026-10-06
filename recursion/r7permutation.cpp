//permutations of a string

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(string str, int index, vector<string> &ans){
    //base case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++){
        swap(str[index],str[j]);
        solve(str,index+1,ans);
        swap(str[index],str[j]); //backtracking
    }
}

int main(){
    string str = "abc";
    int index = 0;
    vector<string> ans;

    solve(str,index, ans);

    for(const auto& word : ans){
        cout<<word<<" ";
    }
    return 0;
}
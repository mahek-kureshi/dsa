// Phone keypad and backtracking

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string digit, int index, string output,vector<string>& ans,string mapping[] ){
    //base case 
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int num = digit[index] - '0';
    string val = mapping[num];

    for(int i=0; i < val.length(); i++){  //imp
        output.push_back(val[i]);
        solve(digit,index+1,output,ans,mapping);
        output.pop_back(); //Backtracking
    }

}

int main(){
    string digit = "35";
    int index = 0;
    string output;
    vector<string> ans;
    string mapping[10] = { "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digit, index,output, ans,mapping);

        for (const string& word : ans) {
        cout << word << " ";
    }


    return 0;
}
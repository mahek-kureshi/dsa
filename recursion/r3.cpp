//to generate subsets 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void solve( vector<int> set, vector<vector<int>> &ans, int index, vector<int> output){
    //base case
    if (index >= set.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(set, ans, index+1, output);

    //include
    int element = set[index];
    output.push_back(element);
    solve(set, ans, index+1, output);
}
int main(){
    vector<int> set = {1,2,3};
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    solve(set,ans,index,output);

    //range-based loops
    //syntax:
    // for(type variable : container)
    // for every element in container, do something
    //outer loop prints subsets, inner loop prints elements inside each subset
    for(const auto& subset : ans){
        for(int val : subset){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}


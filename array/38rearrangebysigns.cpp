//optimal solution to rearrange array elements by sign
// if number of pos and neg elements are not equal
//here we fall back to brute force solution

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,1,9,-2,-5,2,-4,8};
    int n= arr.size();
    vector<int> pos;
    vector<int> neg;

    //to separate pos and neg
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }

    //if pos are greater in number than neg
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }

        int index = neg.size() * 2;
        for(int i=neg.size(); i< pos.size(); i++){
            arr[index]=pos[i];
            index++;
        }
    }

    //if neg are greater in number than pos
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }

        int index = pos.size() * 2;
        for(int i=pos.size(); i< neg.size(); i++){
            arr[index]=neg[i];
            index++;
        }
    }

       for(int i=0; i<n; i++){
        cout<< arr[i] <<endl;
    }
    return 0;
}
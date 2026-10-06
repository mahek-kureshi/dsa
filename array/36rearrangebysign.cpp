//brute force solution to rearrange array elements by sign

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n= arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }

    for(int i=0; i<n/2 ; i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }

    for(int i=0; i<n; i++){
        cout<< arr[i] <<endl;
    }
    return 0;
}
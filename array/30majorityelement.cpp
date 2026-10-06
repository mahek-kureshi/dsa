//better solution to find the majority element present in the array (>n/2 times)
//hashing

#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[]={2,2,3,3,1,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    map<int,int> mpp;

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second > n/2){
             cout << "The majority element is " << it.first << endl;
            return 0; // stop after finding the majority element
        }
    }
    cout << "No majority element found" << endl;
    return 0;
}
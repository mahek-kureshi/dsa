#include<bits/stdc++.h>
using namespace std;

// hashing through array
// works only for small range of numbers

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>> arr[i];
    }
    cout<<"input taken"<<endl;
    //precompute
    int hash[13]={0};
    for(int i=0; i<n;i++){
        hash[arr[i]]+=1;
    }
    cout<<"precomputation done"<<endl;
    int q;
    cin>> q;
    while (q--){
        int number;
        cin>> number;
        cout<<hash[number]<<endl;
    }
    
    return 0;
}
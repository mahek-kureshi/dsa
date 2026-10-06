#include<bits/stdc++.h>
using namespace std;

// through map, hashing is done automatically
// works for large range of numbers also 

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    map<int,int> mpp;
    for (int i=0; i<n; i++){
        mpp[arr[i]] ++;
    }

    //query
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout << mpp[number]<<endl;
    }
}
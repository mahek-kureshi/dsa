//better solution to find the missing element in the array
//hashing

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,4,5};
    int n= sizeof(arr) / sizeof(arr[0]);
    int hash[n+1]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]=1;
    }
    int missing=0;
    for(int i=1; i<n; i++){
        if(hash[i]==0){
        missing = i;
        break;
    }
    }
   cout << "Missing number is: " << missing << endl;

    return 0;
}
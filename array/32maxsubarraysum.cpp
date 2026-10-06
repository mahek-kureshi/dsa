//brute force solution to find the maximum subarray sum

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n= sizeof(arr)/sizeof(arr[0]);

    int maxi=INT_MIN;
    int sum=0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum=0;
           for(int k=i; k<=j; k++){
            sum+=arr[k];
            maxi=max(maxi,sum);
           } 
        }
    }

    cout<<"the maximum subarray sum is "<<maxi<<endl;

    return 0;
}
//Brute force approach to find the length of longest subarray with sum k

#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[]={1,2,3,1,1,1,1,4,2,3};
    int n= sizeof(arr);
   int k=3;
   int len=0;
   //two-pointer approach
   for(int i=0; i<n; i++){
     int sum=0;
    for(int j=i; j<n; j++){
       sum += arr[j];
       if(sum==k){
        len= max(len,j-i+1);
       }
    }
    } 
   cout<< len;
    return 0;
}


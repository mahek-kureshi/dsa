//Solution to find maximum consecutive ones

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,1,0,1,1,1,0,1,1};
    int n= sizeof(arr) / sizeof(arr[0]);
    int counter =0;
    int maxi=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            counter++;
            maxi = max(maxi,counter);
        }
        else{
            counter=0;
        }
    }
    cout<<"the maximum number of times consecutive ones occur is "<<maxi<<endl;
    
    return 0;
}
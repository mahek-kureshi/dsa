//Brute force solution to find the majority element in the array (> n/2 times)
//linear search

#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[]={2,2,3,3,1,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int counter=0;

    for( int i=0; i<n; i++){
        counter=0;

        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]){
                counter++;
            }
            if(counter > n/2){
            cout<< " the majority element is "<<arr[j]<<endl;
            return 0;
        } 
        }  
    }
    return 0;
}
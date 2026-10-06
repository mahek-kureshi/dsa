//optimal solution to rearrange array elements by sign

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n= arr.size();
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n; i++){
        if(arr[i]<0){
            arr[negIndex]=arr[i];
            negIndex += 2;
        }
        else{
            arr[posIndex]=arr[i];
            posIndex += 2;
        }
    }

    for(int i=0; i<n; i++){
        cout<< arr[i] <<endl;
    }

    return 0;
}
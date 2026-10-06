// brute force approach to move all zeros to the end 
#include<iostream>
#include<vector>
using namespace std;

void movezeros(int arr[], int n){
    vector<int> temp;
    int count = 0;
    for(int i=0; i<n; i++){
        if (arr[i] != 0){
            temp.push_back(arr[i]);
            count++;
        }
    }
    for (int i=0; i<count; i++){
        arr[i]=temp[i];
    }
    for(int i=count; i<n ; i++){
        arr[i] = 0;
    }
}

int main(){
    int n=10;
    int arr[]={1,0,2,3,2,0,0,4,5,1};
    movezeros(arr,n);
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<endl;
    }


    return 0;
}
#include<iostream>
using namespace std;

// Program to left rotate the array by one place

void rotate(int nums[], int k) {
        int temp = nums[0];
        for(int i=1; i < k; i++){
            nums[i-1]= nums[i];
        }
        nums[k-1] = temp;
    };

int main(){
    int n=6;
    int arr[] = {1,34,5,32,78,67};
    rotate(arr,n);
    for(int i=0; i<n; i++){
         cout<< arr[i]<<endl;

    }
    return 0;
}
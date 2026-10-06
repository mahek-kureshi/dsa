#include<iostream>
using namespace std;

 int largestElement(int arr[], int n){
    int largest = arr[0];
    for(int i =1; i < n; i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    return largest;
    }; 

int main(){
    int a[10] = {2,3,4, 5,6, 7,12,0,9, 34};
    int ans = largestElement(a,10);
    cout << ans;
    return 0;
}

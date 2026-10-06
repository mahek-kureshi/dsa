#include<iostream>
using namespace std;

// To reverse the array manually

void reverse(int arr[], int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}

int main(){
    int n=6;
 int a[]={1,6,4,3,8,0};
reverse(a,0,5);
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}

}
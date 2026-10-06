#include<iostream>
using namespace std;

int main(){
    int arr[] = {8,4,2,3,5,9,1,2,0};
    int n = sizeof(arr) /sizeof(arr[0]);

 //selection sort code
    for(int i=0; i<n-1; i++){
        int minIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
   
    for (int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}

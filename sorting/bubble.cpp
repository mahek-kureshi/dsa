#include<iostream>
using namespace std;

int main(){
    int arr[] = {8,4,2,3,5,9,1,2,0};
    int n = sizeof(arr) /sizeof(arr[0]);

    for(int i=1; i<n; i++){  //for round 1 to n-1
        bool swapped =false;

        for(int j=0; j< n-i; j++){
          if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped =true;
          }
        }

        if(swapped == false) break;
    }
       

    for (int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
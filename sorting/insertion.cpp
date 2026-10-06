#include<iostream>
using namespace std;

int main(){
    int arr[] = {8,4,2,3,5,9,1,2,0};
    int n = sizeof(arr) /sizeof(arr[0]);

    //bubble sort

    for(int i=1; i<n; i++){  //for round 1 to n-1
        int temp = arr[i];
        int j = i-1;
        for(  ; j>=0; j--){
            if(arr[j] > temp){ //shift hoga yaha not swap
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp; 
    }

    for (int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[s];

    int cnt=0;
    for(int i=s+1; i<= e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    //place at the right place 
    int pI = s + cnt; //pI - pivotIndex
    swap( arr[pI] , arr[s]);

    // left and right part sambhal lenge
    int i=s; 
    int j =e;

    while( i < pI && j > pI){

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] >= pivot){
            j--;
        }

        if(i < pI && j > pI){
            swap( arr[i] , arr[j]);
        }
    }

    return pI;
}

void quickSort(int arr[], int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //partition karenge
    int p = partition(arr, s, e);

    //left part
    quickSort(arr,s,p-1);

    //right part
    quickSort(arr, p+1, e);

}

int main(){
    int arr[] = {8,4,2,3,5,9,1,2,0};
    int n = sizeof(arr) /sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
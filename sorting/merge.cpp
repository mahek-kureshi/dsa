#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid -s +1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int k=s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

    k=mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    //merge two sorted arrays
    int i1=0; //Index1
    int i2=0; //Index2
    int mai = s; //mainArrayIndex

    while(i1 < len1 && i2 < len2){
        if(first[i1] <= second[i2]){
            arr[mai++] = first[i1++];
        }
        else arr[mai++] = second[i2++];
    }

    while(i1 < len1){  
        arr[mai++] = first[i1++];
    }

    while(i2 < len2){  
        arr[mai++] = second[i2++];
    }
}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s >= e){
        return;
    }

    int mid = (s+e)/2;

    //left wala part sort
    mergeSort(arr, s, mid);
    //right wala part sort 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr,s, e);
}

int main(){
    int arr[] = {8,4,2,3,5,9,1,2,0};
    int n = sizeof(arr) /sizeof(arr[0]);
    
    mergeSort(arr, 0, n-1);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
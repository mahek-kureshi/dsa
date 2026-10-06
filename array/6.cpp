// Brute force approach to left rotate an array by d places
#include<iostream>
using namespace std;

void tempor(int arr[], int n , int d){
    d= d % n; 

    // 0 to d step 1, temp mei store
    int temp[d];
    for(int i=0; i<d ; i++){
        temp[i] = arr[i];
    }
    
    //step-2 naye array mei shifted elements, d to n
      int s[n];
      for(int i=d; i<n ; i++){
        arr[i-d]= arr[i];
    }

    
    //step-3 mei temp wale ab yaha pe fill honge, n-d to n
    for(int i=n-d; i<n ; i++){
        arr[i] = temp[i-(n-d)];
    }
    return;
}

int main(){
    int n=7;
    int arr[]={1,2,3,4,5,6,7};
    int d=3;
    tempor(arr,n,d);
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
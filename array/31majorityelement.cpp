//optimal solution to find the majority element in the array (> n/2 times)
//Moore's voting algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    int element;
    int counter=0;
    for(int i=0; i<n; i++){
       if(counter == 0){
        counter=1;
        element=arr[i];
       }
       else if (arr[i] == element){
        counter++;
       }
       else counter--;
    }
    int cnt1=0;
    for(int i=0; i<n; i++){
        if(arr[i]==element) cnt1++;
    }

    if (cnt1 > n / 2)
        cout << "The majority element is " << element << endl;
    else
        cout << "No majority element found" << endl;
        
    return 0;
}
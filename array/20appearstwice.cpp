//better solution to find the number that appears once and the others twice
//hashing by using the concept of arrays

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxi=arr[0];
    for(int i=0; i<n; i++){
        maxi=max(maxi,arr[i]);
    }

    int hash[maxi+1]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    int ans= -1;
    for(int i=0; i<n; i++){
        if(hash[i]==1){
           ans=arr[i]; 
        }
    }
     if (ans != -1)
        cout << "Element appearing once: " << ans << endl;
    else
        cout << "No unique element found" << endl;
        
    return 0;
}

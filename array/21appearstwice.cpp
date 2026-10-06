//better solution to find the number that appears once and the others twice
//hashing by using maps

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans=-1;
    map<long long,int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            ans = it.first;
        }
    }

     if (ans != -1)
        cout << "Element appearing once: " << ans << endl;
    else
        cout << "No unique element found" << endl;
        
    return 0;
}
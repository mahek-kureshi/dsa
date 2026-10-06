//optimal solution to find the number that appears once and others twice
//XOR

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans=-1;

    int XOR=0;
    for(int i=0; i<n; i++){
        XOR=XOR ^ arr[i];
    }
    ans=XOR;
     if (ans != -1 && ans != 0)
        cout << "Element appearing once: " << ans << endl;
    else
        cout << "No unique element found" << endl;
        
    return 0;
}
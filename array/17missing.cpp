//optimal solution to find the missing element 
//using XOR

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,4,5};
    int n= sizeof(arr) / sizeof(arr[0]);
    int XOR1=0;
    int XOR2=0;
    for(int i=0; i<n; i++){
        XOR2 = arr[i] ^ XOR2;
        XOR1 = XOR1 ^ (i+1);
    }
    XOR1 = XOR1 ^ (n+1);
    int ans = XOR1 ^ XOR2;
    cout << "the missing number is "<< ans<<endl;
    return 0;
}
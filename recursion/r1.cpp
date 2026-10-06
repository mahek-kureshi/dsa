// Basics of recursion
//recursion can be solved by iterative approach

// n number of days left for exam!

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void func(int n){
    if(n==0){   //base case or stop page condition
        cout<<"exam starts today!"<<endl;
        return;
    }
    cout<<n<<" days left for exam!"<<endl;
    func(n-1);
    return;
}

int main(){
    int n;
    cout<<"enter the number of days left for exam : ";
    cin>>n;

    // //iterative approach
    // for(int i=n; i>0; i--){
    //     cout<<i<<" days left for exam!"<<endl;
    // }
    // cout<<"exam starts today!";

    //recursive approach
    func(n);

    return 0;
}

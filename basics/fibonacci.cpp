//fibonacci series 0,1,1,2,3,5,8,13,...

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<" enter the nth term you want to see"<<endl;
    cin>>n;
    int last=0;
    int prev=1;
    int current=0;

     cout<< "the fibonacci series is as follows "<<endl;
     cout<<"0 1 ";
    for(int i=1; i<n-1; i++){
        current = last +prev;
        cout << current <<" ";
        last = prev;
        prev = current;

    }
    cout<<endl;
    cout<< current;
    return 0;
}
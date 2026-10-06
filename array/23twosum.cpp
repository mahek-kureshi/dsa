//Brute force solution for two sum problem 
//1st variety-->two sum-->yes or no
//2nd variety-->two sum--> return index i,j

//linear search
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={2,6,5,8,11};
    int n= sizeof(a)/sizeof(a[0]);
    int target=14;

     bool found = false;

    for (int i=0; i<n; i++){
        for(int j=i+1; j<n ; j++){
            // if(i==j) continue; if j=0 se start
            if(a[i]+a[j]==target){
                cout<<"two sum is there"<<endl;
                cout<< i <<" "<< j <<endl;
                found=true;
                break; //breaks inner loop
            }
        }
         if (found) break; // breaks outer loop too
    }
    if(!found){
        cout<<"No such pair found "<<endl;
    }
    return 0;
}
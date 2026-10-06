//Better solution for two sum problem 
//1st variety-->two sum-->yes or no
//2nd variety-->two sum--> return index i,j //optimal for this variety

//Hashing

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[]={2,6,5,8,11};
    int n= sizeof(a)/sizeof(a[0]);
    int target=14;

    map<int,int> mpp;
    for(int i=0; i<n; i++){ 
        int num= a[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded)!= mpp.end()){
            cout<<"two sum pair present"<<endl;
            cout<<"indices " << mpp[moreNeeded] <<" "<< i;
        }
        mpp[num]=i;
    }

    return 0;
}
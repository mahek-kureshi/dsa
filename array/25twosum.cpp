//optimal solution for two sum problem
//1st variety-->two sum-->yes or no
//2nd variety-->two sum--> return index i,j //not for this

//2-pointer approach
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a={2,6,5,8,11};
    int n= a.size();
    int target=14;

     bool found = false;

     int left=0;
     int right=n-1;
    sort(a.begin(),a.end());

while(left < right){
    int sum = a[left]+a[right];
    if(sum==target){
        found =true;
        cout<<"two sum pair exists"<<endl;
        break;
    }
    else if(sum < target) left++;
    else right--;
}

if(!found) {
    cout<<"no such pair exists"<<endl;
}
    return 0;
}
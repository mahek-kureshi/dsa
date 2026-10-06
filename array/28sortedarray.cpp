//optimal solution to sort an array of 0's, 1's, 2's
//dutch national flag algorithm
//using three pointers--low,high,mid 

#include<bits/stdc++.h>
using namespace std;

int main(){
     vector<int> nums={0,1,2,0,1,2,1,2,0,0,0,1};
     int n= nums.size();

        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }

 
        for(int i=0; i<n;i++){
            cout<<nums[i]<<" ";
        }
    return 0;
}

//best solution to find the length of the longest subarray with sum k
//best for +ve numbers

#include<bits/stdc++.h>
using namespace std;

int longestsubarray(vector<int> a, long long k){
   int right=0;
   int left=0;
   int n=a.size();
   int maxlen=0;
   long long sum= a[0];
   while(right<n){
    if(sum > k && left <= right){
        sum -= a[left];
        left++;
    }
    if(sum==k){
        maxlen=max(maxlen, right-left+1);
    }

    right++;
    if(right < n){
        sum += a[right];
    }
   }
    return maxlen;
}

int main(){
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
   int k=6;
    int m =longestsubarray(arr,k);
    cout<<m;
    return 0;
}
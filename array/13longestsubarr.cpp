//better solution to find the lenght of longest subarray with sumk
//this is the best solution for +ve,-ve numbers
#include<bits/stdc++.h>
using namespace std;

int longestsubarray(vector<int> a, long long k){
    map<long long,int> preSumMap;
    long long sum=0;
    int maxlen=0;
    int n = sizeof(a);
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem= sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len =(i-preSumMap[rem]);
            maxlen = max(maxlen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxlen;
}

int main(){
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
   int k=3;
    int m =longestsubarray(arr,k);
    cout<<m;
    return 0;
}
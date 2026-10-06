//sliding window maximum
#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax1(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> ans;
    
    for(int i=0; i<=n-k;i++){
        int maxi = arr[i];
        for(int j=i; j<=i+k-1; j++){
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }

    return ans;
}

class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int>& num, int k){
        deque<int> dq;
        vector<int> result;
        int n = num.size();

        for(int i =0; i < n; i++){
            if(!dq.empty() && dq.front() <= i-k){ //remove elements
                dq.pop_front();
            }
            while(!dq.empty() && num[dq.back()] < num[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1){
                result.push_back(num[dq.front()]);
            }
        }
        return result;
    }
};

int main(){
    vector<int> num = {1,3,-1,-3,5,3,2,1,6};
    vector<int> ans = slidingWindowMax1(num,3);

    Solution obj;
    int k = 3;
    vector<int> ans1 = obj.maxSlidingWindow(num,k);

    for( int i : ans1){
        cout<<i<<" ";
    }
    return 0;
}
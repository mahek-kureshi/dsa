//sum of subarrays minimum
#include<bits/stdc++.h>
using namespace std;

int sum1(vector<int>& arr){
    int sum = 0;
    int mod = (int)(1e9 + 7 );
    int n = arr.size();
    for (int i=0; i < n; i++ ){
        int mini = arr[i];
        for(int j=i; j<n; j++){
            mini = min(mini, arr[j]);
            sum = (sum + mini)%mod;
        }
    }
    return sum;
}
vector<int> nse(vector<int> arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n:st.top();
        st.push(i);
    }
    return nse;
}

vector<int> psee(vector<int> arr){
    int n = arr.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        psee[i] = st.empty() ? -1: st.top();
        st.push(i);
    }
    return psee;
    
}

int sum2(vector<int> arr){
    int n= arr.size();
    int mod = (int)(1e9 +7);
    long long total = 0;
    vector<int> nse1 = nse(arr);
    vector<int> psee1  = psee(arr);
    
    for(int i=0; i<n; i++){
        //number of choices on left and right
        long long left = i-psee1[i];
        long long right = nse1[i] - i;
        //contribution of arr[i]
        long long contri = (1LL * right *left * arr[i])%mod;
        total = (total + contri)%mod;
    }
    return total;
}

int main(){
    vector<int> arr = {3,1,2,4};
    int ans = sum2(arr);
    cout<<ans;
    return 0;
}
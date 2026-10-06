//sum of subarray ranges - matlab sum of difference of largest and smallest element of subarrays
#include<bits/stdc++.h>
using namespace std;

int sumofRanges1(vector<int> arr){
    int n = arr.size();
    int sum = 0;
for(int i= 0; i<n; i++){
    int largest = arr[i];
    int smallest = arr[i];

    for(int j=i+1; j<n; j++){
        largest = max(largest, arr[j]);
        smallest = min(smallest,arr[j]);;

        sum = sum + (largest-smallest);
    }
}
return sum;
}

vector<int> nse(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n);

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n:st.top();
        st.push(i);
    }
    return nse;

}

vector<int> psee(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> psee(n);

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        psee[i] = st.empty() ? -1:st.top();
        st.push(i);
    }
    return psee;

}

vector<int> nge(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n);

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        nge[i] = st.empty() ? n:st.top();
        st.push(i);
    }
    return nge;

}
vector<int> pgee(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> pgee(n);

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        pgee[i] = st.empty() ? -1:st.top();
        st.push(i);
    }
    return pgee;

}


int sumMax(vector<int>& arr){
    int n = arr.size();
    long long total= 0;
    int mod = (int )(1e9+7);

    vector<int> pgee1 = pgee(arr);
    vector<int> nge1 = nge(arr);

    for(int i=0; i<n; i++){
        long long left = i - pgee1[i];
        long long right = nge1[i] - i;
        long long contri = (1LL*left*right*arr[i])%mod;
        total = (total + contri)%mod;

    }
    return total;
}

int sumMin(vector<int>& arr){
    long long total = 0;
    int n = arr.size();
int mod = (int) (1e9+7);

    vector<int> psee1 = psee(arr);
    vector<int> nse1 = nse(arr);

    for(int i=0; i<n; i++){
        long long left = i-psee1[i];
        long long right = nse1[i] -i;
        long long contri = (1LL*left*right*arr[i])%mod;
        total = (total + contri)%mod;
    }
    return total;
}

int sumofRanges2(vector<int>& arr){
    return sumMax(arr)-sumMin(arr);
}

int main(){
    vector<int> arr = {1,4,3,2};
    int ans = sumofRanges2(arr);
    cout<<ans;
    return 0;
}
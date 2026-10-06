//Area of largest rectangle in Histogram

#include<bits/stdc++.h>
using namespace std;

int largestRect1(vector<int>& arr){
    int n = arr.size();
    int ans =0;
    for(int i=0; i<n; i++){
        int minheight = INT_MAX;

        for(int j=i; j<n; j++){
            int width = j-i+1;
           minheight = min(minheight,arr[j]);
            int area = minheight * (width);
            ans = max(ans, area);
                }
    }
     return ans; 
}

vector<int> nse(vector<int>& arr){  
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n:st.top();
        st.push(i);
    }
    return nse;
}

vector<int> pse(vector<int>& arr){
int n = arr.size();
    stack<int> st;
    vector<int> pse(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        pse[i] = st.empty() ? -1:st.top();
        st.push(i);
    }
    return pse;
}

int largestRect2(vector<int>& arr){ //better
int n = arr.size();
int ans = 0;
vector<int> nse1 = nse(arr);
vector<int> pse1 = pse(arr);
 for(int i=0; i < n; i++){
    ans = max( ans, arr[i] * (nse1[i]-pse1[i]-1)); 
 }
return ans;
}

int largestRect3(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    int maxarea = 0;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            int element = st.top();
            st.pop();

            // After popping, stack top is Previous Smaller Element
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea,arr[element]*(i-pse-1) );//i is nse here and st.top will be pse

        }
        st.push(i);
    }

    while(!st.empty()){
        int element = st.top(); 
        st.pop();
        
        int nse = n;
        int pse= st.empty() ? -1:st.top();

        maxarea = max(maxarea,arr[element]*(nse-pse-1) );
    }

    return maxarea;
}


int main(){
    vector<int> arr = {2,1,5,6,2,3};
    int ans = largestRect3(arr);
    cout<<ans;
    return 0;
}
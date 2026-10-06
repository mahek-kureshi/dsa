//previous smaller element
#include<bits/stdc++.h>
using namespace std;

vector<int> pse1(vector<int>& arr){
int n = arr.size();
vector<int> pse(n,-1);
for(int i = 0; i<n; i++){
    for(int j = i-1; j >= 0; j--){
        if(arr[j] < arr[i]){
            pse[i]=arr[j];
            break;
        }
    }
}
return pse;
}

vector<int> pse2(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n,-1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = st.top();
        }
        st.push(arr[i]);
    }
    return pse;
}

int main(){
    vector<int> arr = {4,5,2,10,8};
    vector<int> ans = pse2(arr);
    for( int i : ans){
        cout<< i <<" ";
    }
    return 0;
}
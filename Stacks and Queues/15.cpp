//next greater element(only check left side, circular concept not applied here) 
//monotonic stack- either increasing or decreasing
#include<bits/stdc++.h>
using namespace std;

vector<int> nge1(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n,-1);
    for(int i=0; i < n; i++){
        for(int j =i+1; j < n; j++){
            if(arr[j] > arr[i]){
                nge[i]=arr[j];
                break;
            }
        }
    }
    return nge;
}

vector<int> nge2(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
 for(int i = n-1; i >=0 ; i--){
    while(!st.empty() && st.top() <= arr[i] ){
        st.pop();
    }
    if(st.empty()){
        nge[i]=-1;
    }
    else{
        nge[i] = st.top();
    }
    st.push(arr[i]);
 }
 return nge;
}

int main(){
    vector<int> arr = {6,0,8,1,3};
    vector<int> nge= nge2(arr);

    for(int i: nge){
        cout<< i <<" ";
    }

    return 0;
}
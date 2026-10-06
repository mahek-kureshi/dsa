//next greater element(left side then right side also check, circular array concept)
#include<bits/stdc++.h>
using namespace std;

vector<int> nge1(vector<int>& arr){
    int n = arr.size();
    vector<int> nge(n,-1);
    for(int i = 0; i < n; i++ ){
        for(int j = i+1; j <= i+n-1; j++){
            int ind = j % n;
            if(arr[ind] > arr[i]){
                nge[i] = arr[ind];
                break;
            }
        }
    }
    return nge;
}

vector<int> nge2(vector<int> & arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if(i < n){
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(arr[i%n]);
    }
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
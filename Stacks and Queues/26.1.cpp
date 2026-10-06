//online stock span //M-2
//max consecutive days for which the stock price was less than or equal to current day
#include<bits/stdc++.h>
using namespace std;

class StockSpanner{
    private:
    vector<int> findPGE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return ans;
    }
    public:
    vector<int> stockSpan(vector<int> arr){
        int n = arr.size();

        vector<int> pge = findPGE(arr);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            ans[i] = i-pge[i];
        }
        return ans;
    }
};

int main(){
     vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
     StockSpanner obj;
     int n = arr.size();
     vector<int> ans = obj.stockSpan(arr);

     for(int i =0; i<n; i++){
            cout<<ans[i]<<" ";
     }
    
    return 0;
}
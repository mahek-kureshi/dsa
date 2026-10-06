//trapping rainwater problem
#include<bits/stdc++.h>
using namespace std;

int findTotal1(vector<int>& arr){
    int total=0;
    int n= arr.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0] = arr[0];
    for(int i = 1; i<n; i++){
        prefixMax[i] = max(prefixMax[i-1],arr[i]);
    }

    suffixMax[n-1]=arr[n-1];
    for(int i=n-2; i >= 0; i--){
        suffixMax[i] = max(suffixMax[i+1],arr[i]);
    }

    for(int i=0; i < n; i++){
        total += min(prefixMax[i],suffixMax[i]) -arr[i];
    }

    return total;
}

int findTotal2(vector<int>& arr){
    int pmax = 0;
    int smax = 0;

    int n = arr.size();

    int left=0;
    int right=n-1;

    int total = 0;

        while(left < right){
            if(arr[left] <= arr[right]){
                if(pmax > arr[left]){
                    total += pmax -arr[left];
                }
                else{
                    pmax = arr[left];
                }
                left++;
            }
           else{
                if(smax > arr[right]){
                    total += smax -arr[right];
                }
                else{
                    smax = arr[right];
                }
                right--;
            }
        }
  
    return total;
}

int main() {
    vector<int> arr= {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<< findTotal2(arr);
    return 0;
}
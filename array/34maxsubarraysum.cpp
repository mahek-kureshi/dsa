//optimal solution to find the maximum subarray sum

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n= sizeof(arr)/sizeof(arr[0]);

    int maxi = INT_MIN;
    int sum  = 0;
    int ans_start= -1;
    int ans_end= -1;
    int start = -1;

    for(int i=0; i<n; i++){
        if(sum == 0) start= i;
        sum += arr[i];

        if(sum < 0) sum=0;
        if(sum > maxi){
            maxi = sum;
            ans_start= start;
            ans_end= i;
        }
    }
    cout<<"the maximum subarray sum is "<<maxi<<endl;
    cout<<"indices are "<<ans_start<<" "<<ans_end<<endl;
    return 0;
}
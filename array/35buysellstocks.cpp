//best time to buy and sell stocks

#include<bits/stdc++.h>
using namespace std;

int main(){
    int prices[]={7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(prices[0]);

    int maxprofit = 0;
    int mini = prices[0];

    for(int i=0; i<n; i++){
        int cost =  prices[i] - mini;
        maxprofit = max(cost, maxprofit);
        mini = min(mini, prices[i]);
    }

    cout<<"the max profit can be "<<maxprofit<<endl;
    
    return 0;
}
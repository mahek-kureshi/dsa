//online stock span  //M-1
//max consecutive days for which the stock price was less than or equal to current day
#include<bits/stdc++.h>
using namespace std;

class StockSpanner{
    vector<int> prices;
    public:
    StockSpanner(){

    }

    int next(int price){
        prices.push_back(price);
        int count = 1;
        int i = prices.size()-2;
        while(i>=0 && prices[i] <= price){
            count++;
            i--;
        }
        return count;
    }
};

int main(){
    StockSpanner obj;

    cout<<obj.next(7)<<endl;
    cout<<obj.next(2)<<endl;
    cout<<obj.next(1)<<endl;
    cout<<obj.next(3)<<endl;
    cout<<obj.next(3)<<endl;
    cout<<obj.next(1)<<endl;
    cout<<obj.next(8)<<endl;
    
    return 0;
}
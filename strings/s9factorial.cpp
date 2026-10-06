 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

vector<int> factorial(int num){

    vector<int> ans(1,1);

    while(num > 1){
        int carry = 0; 
        int midres;
        int size = ans.size();
        
        for(int i=0; i < size; i++){
            midres = ans[i]*num + carry;
            carry = midres / 10;
            ans[i] = midres % 10;
        }

        while(carry){
            ans.push_back(carry % 10);
            carry/=10;
        }

        num--;
    }

    reverse(ans.begin(),ans.end());

    return ans;
};

 int main(){
    int n;
    cout<< " enter a number : ";
    cin>>n;

    vector<int> ans = factorial(n);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }

    return 0;
 }
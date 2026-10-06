// code to add string

#include<bits/stdc++.h>
using namespace std;

int main(){
    string num1 = "26583";
    string num2 = "698";
 //here humne assume kiya ki num1 >= num2

    int i = num1.size() - 1; //pointer for num1
    int j = num2.size() - 1; //pointer for num2

    int carry =0;
    int midsum = 0;
    string ans;

    for( ; j>=0; j--){
        midsum = (num1[i]-'0') + (num2[j]-'0') + carry;
        carry = midsum / 10;
        char temp = '0' + (midsum % 10);
        ans= temp + ans;
        i--;
    }

    for( ; i>=0; i--){
         midsum = (num1[i]-'0')  + carry;
        carry = midsum / 10;
        char temp = '0' + (midsum % 10);
        ans = temp + ans;
    }
    if(carry==1){
        ans = char(carry) + ans;
    }
    cout<< ans;
    return 0;
}
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

 string inttoroman(int num){

    vector<int> values ={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string ans;
    for(int i=0; i<values.size(); i++){
        while( num >= values[i]){

            ans += symbols[i];
            num -= values[i];
        }
    } 
    
    return ans;
}

 int main(){
    int n;
    cout<< " enter a number (1 to 3999) : ";
    cin>>n;

    cout<<inttoroman(n);

    return 0;
 }
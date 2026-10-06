//Prime number or not

#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    int count=0;
    if(num<2) cout<<"not a prime number"<<endl;
    if(num >= 2){
    for(int i=2; i<num; i++){
        if(num%i==0){
            cout<<"not a prime number"<<endl;
            count++;
            break;
        }
    }
    }
if(count == 0){
    cout<<num<<" is prime number"<<endl;
}
    return 0;
}
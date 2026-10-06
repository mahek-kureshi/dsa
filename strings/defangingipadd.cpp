// code for defanging an ip address
#include<iostream>
using namespace std;

int main(){
    string address = "255.100.25.60";
    string ans;

    for(int i=0; i < address.size(); i++){
        if(address[i] == '.'){
            ans += "[.]";
        }
        else{
            ans += address[i];
        }
    }

    cout<<ans;
    return 0;

}
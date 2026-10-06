// code to check if the string is rotated(clockwise or anticlockwise) by 2 places or not

#include<iostream>
using namespace std;
 
void rotateclockwise(string &s){
    int temp = s[s.size()-1];
    for(int i= s.size()-2; i >= 0; i--){
        s[i+1] = s[i];
    }
    s[0] = temp;
}

void rotateanticlockwise(string &s){
    int temp = s[0];
    for(int i=1 ; i<s.size()-1; i++){
        s[i-1]=s[i];
    }
    s[s.size()-1] = temp;
}

int main(){
    string str1 = "amazon";
    string str2 = "onamaz";

    if(str1.size() != str2.size()){
        return 0;
    }

    string clockwise, anticlockwise;

    clockwise = str1;
    rotateclockwise(clockwise);
    rotateclockwise(clockwise);

    if(clockwise == str2) cout<<"yes";

    anticlockwise = str1;
    rotateanticlockwise(anticlockwise);
    rotateanticlockwise(anticlockwise);

    if(anticlockwise == str2) cout<<"yes";

    return 0;
}
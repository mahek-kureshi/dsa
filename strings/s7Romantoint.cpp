 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

int num(char c){
    if( c == 'I') return 1;
    else if(c == 'V') return 5;
    else if(c == 'X') return 10;
    else if(c == 'L') return 50;
    else if(c == 'C') return 100;
    else if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    return 0;
}

 int main(){
    string s = "MCCXLVIII";

    int sum = 0;
    for(int i=0; i< s.size()-1; i++){  //going till second last char only

        if( num(s[i]) < num(s[i+1])){
            sum -= num(s[i]);
        }
        else{
            sum += num(s[i]);
        }

    }
      
    sum += num(s[s.size()-1]);  // add last roman numeral
    cout << sum;

    return 0;
 }
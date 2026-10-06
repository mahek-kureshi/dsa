//subsequence of a string - method 2
//bit manipulation
//optional 

//1 → take 'a' 0 → skip 'b' 1 → take 'c'

#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str = "abc";
    int n = str.length();

    int total = 1 << n;   // 2^n

    for(int mask = 1; mask < total; mask++){  // start from 1 to skip empty
        string subsequence = "";

        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                subsequence.push_back(str[i]);
            }
        }

        cout << subsequence << endl;
    }

    return 0;
}

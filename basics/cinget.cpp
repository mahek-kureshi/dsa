#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch;
    ch = cin.get();  // Reads a single character (including spaces, tabs, or newline)

    cout << "Character entered: '" << ch << "'" << endl;
    cout << "ASCII value: " << int(ch) << endl;

    vector<int> arr={45,65,12,32,1,0,9,54};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
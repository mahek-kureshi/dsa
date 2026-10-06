#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    //base case
    if(n==0) return 1;

    return n*factorial(n-1);
}

int fibonacci(int n){
    //base case
    if(n==1 || n==2) return 1;

    int ans = fibonacci(n-1) + fibonacci(n-2);
    return ans;
}

int power(int a, int b){   // a^b
    //base case
    if(b==0) return 1;
    if(b==1) return a;

    //even
    if(b % 2 == 0){
        int ans = power(a,b/2) * power(a,b/2);
        return ans;
    }
    //odd 
    else{
        int ans = power(a,b/2) * power(a,b/2) * a;
        return ans;
    }
}

  bool checkPalindrome(string &str, int i, int j){
    //base case
    if(i>=j) return true;

    if(str[i] != str[j]){
        return false;
    }
    i++;
    j--;
    checkPalindrome(str,i,j);
}

void reverse(vector<int> &arr,int i, int j){
    //base case
    if(i>=j) return;

    swap(arr[i], arr[j]);
    reverse(arr,i+1,j-1);
}

int main(){
    int n = 6;
    int ans1 = factorial(n);

    int num = 6;
    int ans2 = fibonacci(num);

    int a = 2;
    int b = 5;
    int ans3 = power(a,b);

    string name = "aman";
    bool ans4=checkPalindrome(name,0,name.size()-1);
    if(ans4){
        cout<<"it is palindrome!"<<endl;
    }
    else{
        cout<<"it is not a palindrome!"<<endl;
    }

    vector<int> array = {1,3,4,5,7,5,2,1,0};
    reverse(array,0, array.size()-1);

    for(int i=0; i< array.size(); i++){
        cout<<array[i]<<" ";
    }

    cout<<endl<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;

    return 0;
}
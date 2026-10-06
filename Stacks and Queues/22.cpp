//asteroid collisionsarr
#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> arr){  //my approach
    int n = arr.size();

    int i =0;
    int j =n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    return arr;
}

vector<int> finalState1(vector<int> arr){
int n= arr.size();
stack<int> st; 
vector<int> ans;

for(int i=0; i<n; i++){
bool alive = true;

  // no need of this "|| (st.top() < 0 && arr[i]>=0" coz asteroid will move in opp direction
    while(alive && !st.empty() && (st.top() > 0 && arr[i]<0) ) { //opposite sign matlab opposite direction mei asteroid
        if(abs(arr[i]) > abs(st.top())){
            st.pop();
        }
        else if(  abs(arr[i]) == abs(st.top())){
            //both explode
                st.pop();
                alive = false;
            }
        else{
            //current explode;
            alive = false;
        }

        
    }
    if(alive){
            st.push(arr[i]);
        }

}

while(!st.empty()){
ans.push_back(st.top());
st.pop();
}

ans = reverse(ans);

return ans;
}

vector<int> finalState2(vector<int>& arr) { //striver's approach

    vector<int> st;   // using vector as a stack

    for(int i = 0; i < arr.size(); i++) {

        // Positive asteroid
        if(arr[i] > 0) {
            st.push_back(arr[i]);
        }

        // Negative asteroid
        else {

            // Destroy all smaller positive asteroids
            while(!st.empty() &&
                  st.back() > 0 &&
                  st.back() < abs(arr[i])) {

                st.pop_back();
            }

            // Equal size: both explode
            if(!st.empty() &&
               st.back() > 0 &&
               st.back() == abs(arr[i])) {

                st.pop_back();
            }

            // No positive asteroid remains to destroy current asteroid
            else if(st.empty() || st.back() < 0) {

                st.push_back(arr[i]);
            }
        }
    }

    return st;
}

int main(){
    vector<int> arr = {4,7,1,1,2,-3,-7,17,15,-16};
    vector<int> ans  = finalState2(arr);
    for(int i: ans){
            cout<<i<<" ";
    }
    return 0;
}
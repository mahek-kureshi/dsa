// Brute force approach to find Intersection of two sorted arrays
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> intersec(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int vis[n2] = {0};
    vector<int> ans;
    for(int i=0; i<n1 ; i++){
        for(int j=0; j<n2 ; j++){
            if(arr1[i] == arr2[j] && vis[j] == 0){
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }  
            if(arr1[i] < arr2[j]) break;
        }
    }
    return ans;
};

int main(){
    int n1 = 6;
    int n2 = 6;
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    vector<int> result = intersec(arr1, arr2);

        for (int num : result){
            cout<< num << endl;
        }
    return 0;
}
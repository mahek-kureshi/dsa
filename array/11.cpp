//  optimal solution to find intersection of two sorted arrays
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> intersec(vector<int>& arr1, vector<int>& arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans;

    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else if (arr1[i] > arr2[j]){
            j++;
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
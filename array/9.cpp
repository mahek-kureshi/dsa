// optimal solution for to get the union of two sorted arrays
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> findunion(vector<int>& arr1, vector<int>& arr2){
    int i=0;
    int j=0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j] ){
            if( unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }

        else{
            if( unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        
            if( unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    
    while(i<n1){
        
            if( unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        
    }
    return unionArr;
}
int main(){
    int n1 = 6;
    int n2 = 6;
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    vector<int> result = findunion(arr1, arr2);

        for (int num : result){
            cout<< num << endl;
        }
    return 0;
} 
// brute force approach to get union of two sorted array
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> findunion(int arr1[], int arr2[], int n1, int n2 ){
    // set mei daalna
    set<int> st;
    for(int i=0; i<n1 ; i++ ){
        st.insert(arr1[i]);
    }
     for(int i=0; i<n2 ; i++ ){
        st.insert(arr2[i]);
    }
    // wapis arr mei dalna
    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}
int main(){
    int n1 = 6;
    int n2 = 6;
    int arr1[] = {1,1,2,3,4,5};
    int arr2[] = {2,3,4,4,5,6};

    vector<int> result = findunion(arr1, arr2, n1,n2);

        for (int num : result){
            cout<< num << endl;
        }
    return 0;
} 
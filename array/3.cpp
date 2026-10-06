#include<iostream>
#include <set>
using namespace std;

//remove duplicate from sorted array
int removeduplicate(int arr[], int n){
    set<int> st;
    for(int i=0; i <n ; i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for( auto it : st){
        arr[index] = it;
        index++ ;
    }
    return (index);
}

int main(){
    int n = 7;
    int a[]={2,45,45,78,88,88,97};
    int RD = removeduplicate( a, n);
    cout<< "after removing the duplicate elements , the total size of array is "<< RD <<endl;
    cout<< " the unique elements are "<<endl;
    for ( int i=0; i<RD; i++){
        cout<< a[i]<<endl;
    }
    return 0;
}
#include<iostream>
#include <climits>   // required for INT_MIN and INT_MAX
using namespace std;

int secondSmallest(int a[], int n){
        int smallest=a[0];
        int ssmallest = INT_MAX;
        for(int i =1; i < n; i++){
            if(a[i]< smallest){
                ssmallest= smallest;
                smallest= a[i];
            }       
            else if(a[i]> smallest && a[i]< ssmallest){
                ssmallest = a[i];
            }
            return ssmallest;
            }
    };
    int secondLargest(int a[], int n) {
        int largest = a[0];
        int slargest = INT_MIN;

        for(int i=1; i < n; i++){
            if(a[i]>largest){
                slargest=largest;
                largest= a[i];
            }
            else if(a[i] < largest && a[i] > slargest){
                slargest = a[i];
            }
        }
        return slargest;
    };

int main(){
    int a[]= {1,6,89, 45, 99, 342, 2, 5, 67,23};
    int n =10;
    int slargest = secondLargest(a,n);
    int ssmallest = secondSmallest(a,n);
 
    cout << "Second Largest = " << slargest << endl;
    cout << "Second Smallest = " << ssmallest << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    // Node x = Node(2,nullptr);
    // Node *y = &x; 
    // cout<< y;
    // cout<< x.data;
    // cout<<x.next;
 
    Node * y = new Node(3, nullptr);
    cout<< y <<endl; //0x1151a78
    cout<< y->data;
    cout<<endl<< y->next; //0
    return 0;
}
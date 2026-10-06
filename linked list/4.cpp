#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node * next;

    public:
    Node(int data1, Node * next1){
        data = data1;
        next= next1;
    }

    Node(int data1){
        data= data1;
        next= nullptr;
    }
};

Node * convertArr2LL(vector<int> arr){
    Node * head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i < arr.size(); i++){
        Node * temp =new Node(arr[i]);
        mover->next  = temp;
        mover = mover->next;
    }
    return head;
}

void print(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node * removeK(Node * head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node * temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node * temp = head;
    Node * prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node * removeEl(Node * head, int val){
    if(head==NULL) return head;
    if(head->data == val){
        Node * temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node * temp = head;
    Node * prev = NULL;
    while(temp != NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 6, 7,8};
    Node* head = convertArr2LL(arr);
    head = removeEl(head,9);
    print(head);
    cout<<endl;


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
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

Node * findMiddle(Node * head){
    Node * slow = head;
    Node * fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
};

Node * mergeTwoLists(Node * list1,Node * list2){
    Node * dummynode = new Node(-1);
    Node * temp = dummynode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummynode->next;
};

Node * sortLL(Node * head){
    if(head == NULL || head->next == NULL) return head;

    Node * middle = findMiddle(head);
    Node * right = middle->next;
    middle->next = nullptr;
    Node * left = head;

    left = sortLL(left);
    right = sortLL(right);

    return mergeTwoLists(left, right);
};


int main(){
    vector<int> arr= {3,7,81,2,3,45,9,2,1,0,-2};
    Node* head = convertArr2LL(arr);
    head = sortLL(head);
    print(head);
    

    return 0;
}
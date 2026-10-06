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

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i< arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node * deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp= head;
    head = head->next;
    head->back= nullptr;
    temp->next = nullptr;

    delete temp;
    return head;
}

Node * deleteTail(Node * head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node * prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;// here temp is tail and prev is new tail
    delete temp;
    return head;
}

Node * removeKthElement(Node * head, int k){
    if(head == NULL){
        return NULL;
    }
    Node * temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp= temp->next;
    }
    Node * prev = temp->back;
    Node * front = temp->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }

    if(prev==NULL){
        return deleteHead(head);
    }

    if(front==NULL){
        return deleteTail(head);
    }

    prev->next = temp->next;
    front->back = temp->back;

    temp->next= nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void deleteNode(Node * temp){
    Node * prev = temp->back;
    Node * front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
    return;
}

int main(){
    vector<int> arr= {12, 5, 8,7};
    Node* head = convertArr2DLL(arr);
    // head = removeKthElement(head,3);
    deleteNode(head->next->next);
    print(head);

    return 0;
}
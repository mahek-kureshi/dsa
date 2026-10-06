#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    public:
    Node(int data1, Node * next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

Node * convertArr2LL(vector<int>& arr){
        Node * head = new Node(arr[0]);
        Node * mover = head;
        for(int i=1; i<arr.size(); i++){
            Node * temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
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

    Node * removesHead(Node * head){
        if(head == NULL) return head;
        Node * temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node * removeTail(Node * head){
        if(head == NULL || head->next == NULL) return NULL;
        Node * temp= head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
        return head;
    }

int main(){
    vector<int> arr = {12, 5, 6, 7,8};
    Node* head1 = convertArr2LL(arr);
    print(head1);
    cout<<endl;
    // Node* head2 = removesHead(head1);
    // print(head2);

    Node * head2 = removeTail(head1);
    print(head2);
    return 0;
}
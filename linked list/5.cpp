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

Node * insertHead(Node * head,int val){
    Node * newHead = new Node(val,head);
    return newHead;
}

Node * insertTail(Node * head, int val){
    if(head==NULL) return new Node(val);

    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node * newNode= new Node(val);
    temp->next = newNode;
    return head;
}

Node * insertPosition(Node * head, int val, int k){
    if(head == NULL){
        if(k==1){
            Node * newNode = new Node(val);
            return newNode;
        }
        else{
            return head;
        }
    }

    if(k==1){
        return new Node(val,head);
    }

    int cnt= 0;
    Node * temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node * x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node * insertBeforeEl(Node * head, int val, int el){ //before element el
    if(head == NULL){
        return NULL;
    }

    if(head->data == el){
        return new Node(val,head);
    }

    Node * temp = head;
    while(temp->next != NULL){
        if(temp->next->data == el){
            Node * x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 6, 7,8};
    Node* head = convertArr2LL(arr);
    head = insertBeforeEl(head, 16, 6);
    print(head);
    cout<<endl;
    return 0;
}
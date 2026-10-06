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

Node * insertBeforeHead(Node * head, int val){
    Node * newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}

Node * insertBeforeTail(Node * head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head,val);
    }
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node * prev = temp->back;
    Node * newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;

}

Node * insertBeforeKthElement(Node * head, int k, int val){
    if(k==1){
        return insertBeforeHead(head,val);
    }
    Node * temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp = temp->next;
    }
    Node * prev = temp->back;
    Node * newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node * node, int val){
    Node * prev = node->back;
    Node * newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

Node * insertAfterTail(Node * head, int val){
    if(head== NULL){
        return new Node(val);
    }
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node * newNode = new Node(val, nullptr, temp);
    temp->next = newNode;
    return head;
}

Node * reverseDLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node * prev = NULL;
    Node * current = head;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        current = current->back;
    }
    return prev->back;
}

Node* addTwoNumbers(Node* num1, Node* num2) {
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;

    Node* temp1 = num1;
    Node* temp2 = num2;

    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry) {

        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10;

        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return dummyHead->next;

}
void print1(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> arr= {2, 5, 8,7};
    Node* head = convertArr2DLL(arr);
    // head = insertBeforeHead(head, 100);
    // head = insertBeforeTail(head,120);
    // head = insertBeforeKthElement(head, 3, 190);
    // insertBeforeNode(head->next->next,180);
    // Node * head1 = insertAfterTail(head,8);
    // Node * head2 = reverseDLL(head);
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);

    Node* head3 = addTwoNumbers(head1, head2);

    print1(head3);

    return 0;
}
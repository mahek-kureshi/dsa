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

Node * convertArr2LL(vector<int> &arr){
    Node * head = new Node(arr[0]);
    Node * mover = head;

    for(int i=1; i<arr.size(); i++){
        Node * temp = new Node(arr[i]);
        mover->next = temp;
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

Node * findIntersection1(Node * head1, Node * head2){
    map<Node *, int> mpp;
    Node * temp = head1;
    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){
        if (mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Node * collisionPoint(Node* t1, Node * t2, int d){
    while(d){
        d--;
        t2 = t2->next;
    }
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

Node * findIntersection2(Node * head1, Node * head2){
    Node * temp = head1;
    int cnt1 = 0;
    while(temp){
        cnt1++;
        temp = temp->next;
    }
    temp = head2;
    int cnt2 = 0;
    while(temp){
        cnt2++;
        temp = temp->next;
    }
    if(cnt1 < cnt2){
        return collisionPoint(head1,head2, cnt2-cnt1);
    }
    else{
        return collisionPoint(head2,head1, cnt1-cnt2);
    }
}

Node * findIntersection3(Node * head1, Node * head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node * t1 = head1;
    Node * t2 = head2;

    while( t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

    if(t1 == t2){
        return t1;
    }

    if(t1 == NULL){
        t1 = head2;
    }

    if(t2 == NULL){
        t2 = head1;
    }

    }
    return t1;
}

int main(){
    // Common/intersecting part
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);


    // First Linked List: 1 -> 2 -> 3 -> 7 -> 8 -> 9
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Connect first list to common part
    head1->next->next->next = common;


    // Second Linked List: 4 -> 5 -> 7 -> 8 -> 9
    Node* head2 = new Node(4);
    head2->next = new Node(5);

    // Connect second list to common part
    head2->next->next = common;

    // Find intersection
    Node* intersection = findIntersection3(head1, head2);

    if (intersection != NULL) {
        cout << "Intersection point: "
             << intersection->data << endl;
    }
    else {
        cout << "No intersection" << endl;
    }

    return 0;
}
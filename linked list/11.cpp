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

bool detectLoop1(Node * head){
    map<Node*,int> mp;
    Node * temp = head;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return true;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

bool detectLoop2(Node * head){
    Node * slow = head;
    Node * fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

int lengthofLoop1(Node * head){
    map<Node*, int> mp;
    Node * temp = head;
    int timer = 1;

    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            int value = mp[temp];
            return (timer - value);
        }
        mp[temp]= timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int findlength(Node * slow, Node * fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        fast = fast->next;
        cnt++;
    }
    return cnt;
}

int lenghtofLoop2(Node * head){
    Node * slow = head;
    Node * fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return findlength(slow,fast);
        }
    }
    return 0;
}

Node * startofLoop1(Node * head){
    map<Node*, int> mp;
    Node * temp = head;

    while(temp != NULL){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
        mp[temp]=1;
        temp=temp->next;
    }
    return temp;
}

Node * startofLoop2(Node * head){
    Node * slow = head;
    Node * fast = head;

while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            slow = head;
            while(slow != fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
return NULL;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating loop:
    // 5 -> 3
    head->next->next->next->next->next = head->next->next;

if (detectLoop2(head)) {
        cout << "Loop detected" << endl;
    }
    else {
        cout << "No loop detected" << endl;
    }

    int len = lengthofLoop1(head);
    cout<<"length of loop is "<<len;

    Node * start = startofLoop2(head);
    cout<<endl<<start->data<<endl;

    return 0;
}
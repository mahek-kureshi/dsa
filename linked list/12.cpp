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

Node * deletekey(Node * head, int key){
    Node * temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node * nextnode = temp->next;
            Node * prevnode = temp->back;

            if(nextnode != NULL) nextnode->back = prevnode;
            if(prevnode != NULL) prevnode->next = nextnode;

            free(temp);
            temp = nextnode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

vector<pair<int,int>> findPairs1(Node * head, int sum){
    vector<pair<int,int>> ds;
    Node * temp1 = head;
    while(temp1 != NULL){
        Node * temp2 = temp1->next;
        while(temp2 != NULL && ((temp1->data + temp2->data) <= sum)){
            if(temp1->data + temp2->data == sum){
                ds.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ds;
}

Node * findtail(Node * head){
    Node * tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

vector<pair<int,int>> findPairs2(Node * head, int sum){
    Node * left = head;
    Node * right = findtail(head);
    vector<pair<int,int>> ans;

    while(left->data < right->data){
        if(left->data + right->data == sum){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if (left->data + right->data > sum){
            right = right->back;
        }
        else{
            left = left->next;
        }
    }
    return ans;
}

Node * removeDuplicate(Node * head){
    Node * temp = head;
    while(temp != NULL && temp->next != NULL){
        Node * nextnode = temp->next;
        while(temp->data == nextnode->data && nextnode != NULL){
           Node * duplicate = nextnode;
            nextnode = nextnode->next;
            free(duplicate);
        }
        temp->next = nextnode;
        if(nextnode != NULL) nextnode->back = temp;
        temp = temp->next;
    }
    return head;
}




int main(){
    vector<int> arr= {1,1,1,2,3,3,4};
    Node* head = convertArr2DLL(arr);
    // head = deletekey(head,10);  
    head = removeDuplicate(head);
    print(head);

    // int sum = 5;
    // vector<pair<int,int>> pairs = findPairs2(head,sum);

    // for(auto it : pairs){
    //     cout<<"("<<it.first<<", "<<it.second<<") "<<endl;
    // }
    

    return 0;
}
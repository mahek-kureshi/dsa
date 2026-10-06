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

    Node * oddeven1(Node * head){ //brute force solution
        if(head==NULL){
            return head;
        }
        vector<int> arr;
        Node * temp= head;

        //odd positions
        while(temp != NULL && temp->next != NULL){
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp) arr.push_back(temp->data);

        //even positions
        temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp) arr.push_back(temp->data);

        //rewrite
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }

    Node * oddeven2(Node * head){ //optimal code
        Node * odd = head;
        Node * even = head->next;
        Node * evenHead = even;

        while(even!=NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next= even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }

    Node * sort1(Node * head){ //brute force solution for sorting of 0's 1's 2's
        Node * temp = head;
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        while(temp != NULL){
            if(temp->data == 0){
                cnt0++;
            }
            else if(temp->data == 1){
                cnt1++;
            }
            else if(temp->data == 2){
                cnt2++;
            }
            temp = temp->next;
        }
            temp = head;
            while(temp!=NULL){
                if(cnt0){
                    temp->data = 0;
                    cnt0--;
                }
                else if(cnt1){
                    temp->data = 1;
                    cnt1--;
                }
                else if(cnt2){
                    temp->data =2;
                    cnt2--;
                }
                temp = temp->next;
            }
    
    return head;
    }

    Node * sort2(Node * head){ //optimal solution for sorting of 0 1 2
        Node * zeroHead = new Node(-1);
        Node * oneHead = new Node(-1);
        Node * twoHead = new Node(-1);

        Node * zero =zeroHead;
        Node * one =oneHead;
        Node * two =twoHead;

        Node * temp = head;

        while(temp != NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else if(temp->data == 2){
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        zero->next = (oneHead->next)? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = NULL;

        Node * newHead = zeroHead->next;
        return newHead;
    }

Node * RemoveFromEnd1(Node * head, int N){  //brute force solution
    Node * temp = head; 
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }

    if(cnt == N){
        Node * newHead = head->next;
        free(head);
        return newHead;
    }

    temp = head;
    int res = cnt - N;
    while(temp != NULL){
        res--;
        if(res==0){
            break;
        }
        temp = temp->next;
    }
    Node * delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

Node * removeFromEnd2(Node * head, int N){ //optimal solution
    Node * fast = head;
    Node * slow = head;
    for(int i = 0; i < N; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node * delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}


int main(){
    vector<int> arr = {12, 5, 6, 7,8};
    Node* head1 = convertArr2LL(arr);
    head1 = removeFromEnd2(head1,4);
    print(head1);

    cout<<endl;

    vector<int> arr1 = {1,0,1,2,0,2,1};
    Node * head = convertArr2LL(arr1);
    head = sort2(head);
    print(head);

    return 0;
}
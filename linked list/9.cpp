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

    Node * reverseLL1(Node * head){ // brute force solution to reverse a single LL
        Node * temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
       return head; 
    }

    Node * reverseLL2(Node * head){ //optimal soln to reverse a singly LL
      Node * temp = head;
      Node * prev = NULL;
      while(temp != NULL){
        Node * front = temp->next;
        temp->next = prev;
        prev = temp;
        temp=front;
      }
      return prev;
    }

    Node * reverseLL3(Node * head){// recurrsive way to reverse a singly LL
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node * newHead = reverseLL3(head->next);
        Node * front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(Node * head){ //brute force soln to check whether palindrome or not
        Node * temp = head;
        stack<int> st;

        while(temp != NULL){
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;

        while(temp != NULL){
            if(temp->data != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }

    bool isPalindrome2(Node * head){ //optimal code check palindrome
        if(head == NULL || head->next == NULL){
            return true;
        }
        Node * fast= head;
        Node * slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node * newHead = reverseLL3(slow->next);
        Node * first = head;
        Node * second = newHead;
        while(second != NULL){
            if(first->data != second->data){
                reverseLL3(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL3(newHead);
        return true;
    }

    Node * add1(Node * head){ // brute force approach to add 1 to the LL
        head = reverseLL3(head);
        Node * temp= head;
        int carry=1;

        while(temp != NULL){
            temp->data = temp->data + carry;
            if(temp->data < 10){
                carry = 0;
                break;
            }
            else{
                temp->data = 0;
                carry =1;
            }
            temp = temp->next;
        }
        if(carry == 1){
            Node * newNode = new Node(1);
            head = reverseLL3(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseLL3(head);
        return head;
    }

    int addHelper(Node* temp){ //optimized recursive method to add 1 to singly LL
        if(temp == NULL){
            return 1;
        }
        int carry = addHelper(temp->next);
        temp->data += carry;
        if(temp->data < 10){
            return 0;
        }
        temp->data = 0;
        return 1;
    }

    Node * addOne(Node * head){
        int carry = addHelper(head);
        if(carry == 1){
            Node * newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }

    Node * findMiddle(Node * head){ //brute force approach to find middle of LL
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node * temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int mid = count/2 +1;
        temp = head;

        while(temp != NULL){
            mid = mid-1;
            if(mid == 0){
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    Node * findMiddle1(Node * head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node * slow = head;
        Node * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node * deletemiddle1(Node * head){
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node * temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int beforemid = (n/2);

        temp = head;
        while(temp != NULL){
            beforemid--;
            if(beforemid == 0){
                Node * mid = temp->next;
                temp->next = temp->next->next;
                free(mid);
                break;
            }
            temp = temp->next;
        }

        return head;
    }

    Node * deletemiddle2(Node * head){
        Node * slow = head;
        Node * fast = head->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node * mid = slow->next;
        slow->next = slow->next->next;
        free(mid);
        return head;
    }

int main(){
    vector<int> arr = {1, 5, 6, 7,8};
    Node* head = convertArr2LL(arr);
    // head = reverseLL3(head);
    // cout<< isPalindrome(head)<<endl;
    // head = addOne(head);
    Node * middleNode = findMiddle1(head);
    cout<<middleNode->data<<endl;
    head = deletemiddle1(head);
    print(head);

    return 0;
}
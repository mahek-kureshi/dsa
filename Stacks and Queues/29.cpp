//LRU Cache
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
    class Node{

        public:
        int key;
        int val;
        Node * next;
        Node * prev;

        Node(int key1, int val1){
            key = key1;
            val = val1;
        }

    };

    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;

    }

    void addNode(Node * newNode){
        Node * temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;

    }

    void deleteNode(Node * delNode){
        Node * delPrev = delNode->prev;
        Node * delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;

    }

    int get(int key1){
        if(m.find(key1) != m.end()){
            Node * resNode = m[key1];
            int res = resNode->val;

            m.erase(key1);
            deleteNode(resNode);

            addNode(resNode);
            m[key1] = head->next;

            return res;
        }
        return -1;

    }

    void put(int key1, int value1){
        if(m.find(key1) != m.end()){
            Node * existingNode = m[key1];

            m.erase(key1);
            deleteNode(existingNode);
        }

        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key1,value1));
        m[key1] = head->next;

    }
};

int main() {
    LRUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<endl;
    cache.put(3,3);
    cout<<cache.get(2)<<endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl; 
    cout << cache.get(4) << endl; 
    return 0;
}
// LFU Cache
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key,val,cnt;
    Node * next;
    Node * prev;
    Node(int key1, int val1){
        key = key1;
        val = val1;
        cnt = 1;
    }
};

struct List{
    Node * head;
    Node * tail;
    int size;

    //constructor
    List(){
        head =  new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;

    }

    void addFront(Node * node){
        Node * temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;

    }

    void removeNode(Node * delNode){
        Node * delPrev = delNode->prev;
        Node * delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache{
    private:

    map<int,Node*> keyNode;
    map<int,List*> freqListMap;

    int maxSizeCache;

    int minFreq;

    int curSize;

    public:
    //constructor
    LFUCache(int capacity){
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;

    }

    void updateFreqListMap(Node * node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }

        List * nextHigherFreqList = new List();

        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key){

        if(keyNode.find(key) != keyNode.end()){
            Node * node = keyNode[key];
            int val1 = node->val;

            updateFreqListMap(node);

            return val1;
        }

        return -1;
    }
    void put(int key, int val){
        if (maxSizeCache == 0){
            return;
        }

        if(keyNode.find(key) != keyNode.end()){
            Node * node = keyNode[key];
            node->val = val;

            updateFreqListMap(node);
        }
        else{
            if(curSize == maxSizeCache){
                List * list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq =1;

            List * listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }

            Node * node = new Node(key,val);

            listFreq->addFront(node);

            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }

    }


};

int main(){
    LFUCache cache(2);

    cache.put(1,1);
    cache.put(2,2);
    cout<< cache.get(1)<<endl;
    cache.put(3,3);
    cout<< cache.get(2)<<endl;
    cout<< cache.get(3)<<endl;
    cache.put(4,4);
    cout<< cache.get(1)<<endl;
    cout<< cache.get(3)<<endl;
    cout<< cache.get(4)<<endl;

    return 0;
}
/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

struct LRULinkedList{
    int key;
    LRULinkedList *pre;
    LRULinkedList *next;
    LRULinkedList(int k):key(k),pre(NULL),next(NULL){}
};
struct LRUNode{
    int value;
    LRULinkedList *listNode;
    LRUNode(int v, LRULinkedList *list):value(v), listNode(list){}
};
class LRUList{
private:
    LRULinkedList *remove(LRULinkedList *node){
        if(node->pre == NULL){
            head = node->next;
        }else{
            node->pre->next = node->next;
        }
        if(node->next == NULL){
            tail = node->pre;
        }else{
            node->next->pre = node->pre;
        }
        node->pre = NULL;
        node->next = NULL;
        //delete node;
        //node = NULL;
        return node;
    }
    LRULinkedList *add(LRULinkedList *node){
        if(head == NULL){
            head = tail = node;
            //head->next = tail;
            //tail->pre = head;
        }else{
            //node->next = tail->next;
            node->pre = tail;
            tail->next = node;
            //head->pre = node;
            tail = node;
            //if(ta)
        }
        return tail;
    }
public:
    LRULinkedList *head;
    LRULinkedList *tail;
    void update(LRULinkedList *node){
        remove(node);
        add(node);
    };

    int remove(){
        LRULinkedList *node = remove(head);
        int k = node->key;
        delete node;
        node = NULL;
        return k;
    }
    LRULinkedList *add(int key){
        LRULinkedList *newNode = new LRULinkedList(key);
        return add(newNode);
    }

    LRUList(){
        head = tail = NULL;
    }
};

class LRUCache{
public:
    int capacity;
    LRUList *lrulist;
    map<int, LRUNode *> hashmap;
    LRUCache(int capacity) {
        this->capacity = capacity;
        lrulist = new LRUList();
    }

    int get(int key) {
        map<int, LRUNode *>::iterator it = hashmap.find(key);
        if(it != hashmap.end()){
            lrulist->update(it->second->listNode);
            return it->second->value;
        }
        return -1;
    }
    void set(int key, int value) {
        map<int, LRUNode *>::iterator it = hashmap.find(key);
        if(it != hashmap.end()){
            it->second->value = value;
            lrulist->update(it->second->listNode);
            return;
        }
        int cursize = hashmap.size();
        if(cursize >= capacity){
            int rekey = lrulist->remove();
            hashmap.erase(rekey);
        }
        LRUNode *newNode = new LRUNode(value, lrulist->add(key)); 
        hashmap[key] = newNode;
    }
};
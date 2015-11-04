#include <assert.h>
#include <map>
#include <iostream>
using namespace std;
struct node {
    int val, k;
    node* pre;
    node* next;
    node(int K, int v, node* Pre, node* Next) : k(K), val(v), pre(Pre), next(Next) {};
};

struct Double_List {
    node* head, *tail;
    int cnt;
    Double_List() {
        head = NULL;
        tail = NULL;
        cnt = 0;
    }

    void push_front(int k, int v) {
        cnt++;
        node* temp = new node(k, v, NULL, head);
        head = temp;
        if(tail == NULL) tail = head;
        else head -> next -> pre = head;
    }

    void pop_back() {
        assert(head != NULL);
        cnt--;
        if(tail->pre == NULL) {
            delete tail;
            head = tail = NULL;
        } else {
            tail = tail -> pre;
            delete tail -> next;
            tail -> next = NULL;
        }
    }

    void erase(node* pointer) {
        assert(head != 0);
        cnt--;
        if(pointer == head) {
            if(pointer -> next != NULL) {
                head = head -> next;
                delete head -> pre;
                head -> pre = NULL;
            } else {
                delete head;
                head = tail = NULL;
            }
        } else if (pointer == tail){
            tail = tail -> pre;
            delete tail -> next;
            tail -> next = NULL;
        } else {
            pointer -> pre -> next = pointer -> next;
            pointer -> next -> pre = pointer -> pre;
            delete pointer;
        }
    }

    node* begin() { return head; }
    node* end() { return tail; }
    int size() { return cnt; }
};

class LRUCache{
public:

    int lim;
    Double_List DL;
    std::map<int, node*> mp;
    LRUCache(int capacity) {
        lim = capacity;

    }

    int get(int key) {
        if(mp.count(key) == 0) return -1;
        int val = mp[key]->val;
        DL.erase(mp[key]);
        DL.push_front(key, val);
        mp[key] = DL.begin();
        return DL.begin()->val;
    }

    void set(int key, int value) {
        if(mp.count(key) == 0) {
            if(mp.size() == lim) {
                mp.erase(DL.end()->k);
                DL.pop_back();
            }
            DL.push_front(key, value);
            mp[key] = DL.begin();
        } else {
            DL.push_front(key, value);
            DL.erase(mp[key]);
            mp[key] = DL.begin();
        }
    }
};

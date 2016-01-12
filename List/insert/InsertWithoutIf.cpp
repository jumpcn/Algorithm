#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node {
    int v;
    node* next;
    node(int _v = 0, node* n = NULL) : v(_v), next(n) {
        cout << v << " " << n << endl;
    }
};

void insert(node** head, int v) {
    while(*head && (*head)->v < v) {
        (*head) = (*head)->next;
    }
    (*head) = new node(v, (*head));
}

node* insert_2(node* head, int v) {
    node* t = head;
    if(t == NULL) return new node(v, NULL);
    while(t) {
        if(t -> next == NULL) {
            t -> next = new node(v, NULL);
        } else if(t -> v >= v) {
            if(t == head) return new node(v, t -> next);
            t -> next = new node(v, t -> next);
            break;
        }
        t = t->next;
    }
    return head;
}

void show(node* h) {
    int cnt = 0;
    while(h) {
        cout << h->v << "->";
        cout << flush;
        if(cnt++ > 100) break;
        h = h -> next;
    }
    cout << endl;
}
int main() {
    //node* h = new node(1, new node(2, NULL));
    node* h = new node(1, new node(2, NULL));
    node* t = insert_2(h, 1);
    show(t); 
}


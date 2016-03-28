#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int Max_Node = 50000000;
struct node{
    int v, height, size;
    node *ch[2];
    void update() {
        height = max(ch[0]->height, ch[1]->height) + 1;
        size = ch[0]->size+ch[1]->size+1;
    }
} *null;

node* Mem;
int ptr;
// ch[0] for left, ch[1] for right
node* newNode(int v) {
    node* temp = &Mem[ptr++];
    temp->height = 1;
    temp->v = v;
    temp->size = 1;
    temp->ch[0] = temp->ch[1] = null;
    return temp;
}

void init() {
    ptr = 0;
    null = newNode(0);
    null -> height = 0;
    null -> size = 0;
}

//d = 0, LR, d = 1, RR
void rotate(node* &root, int d) {
    node* temp = root->ch[d];
    root->ch[d] = temp->ch[!d];
    temp->ch[!d] = root;
    root->update();
    temp->update();
    root = temp;
}


void maintain(node* &root, int d) {
    if (root->ch[d]->height - root->ch[!d]->height == 2) {
        if (root->ch[d]->ch[d]->height - root->ch[d]->ch[!d]->height == 1 ) {
            rotate(root, d);
        } else if(root->ch[d]->ch[d]->height - root->ch[d]->ch[!d]->height == -1) {
            rotate(root->ch[d], !d);
            rotate(root, d);
        }
    }
}
void insert(node* &root, int v) {
    if(root == null) {
        root = newNode(v);
        return;
    }
    bool d = v >= root->v;
    insert(root->ch[d], v);
    root->update();
    maintain(root, d);
}

int findMin(node* root) {
    if(root->ch[0] == null) return root->v;
    else return findMin(root->ch[0]);
}
void del(node* &root, int v) {
    if(root == null) return;
    if(v < root->v) del(root->ch[0], v);
    else if(v > root-> v) del(root->ch[1], v);
    else {
        if(root->ch[0] == null || root->ch[1] == null) {
            node* temp = root->ch[0] == null ? root->ch[1] : root->ch[0];
            root = temp;
        } else {
            int Min = findMin(root->ch[1]);
            root -> v = Min;
            del(root->ch[1], Min);
        }
    }
    if(root!=null) {
        root->update();
        maintain(root, 0);
        maintain(root, 1);
    }
}
int select(node* root, int k) {
    int r = root->ch[0]->size;
    if(k == r) return root->v;
    if(k<r) return select(root->ch[0], k);
    else return select(root->ch[1], k-r-1);
}

int max_height(node* root) {
    if(root == null) return 0;
    return max(max_height(root->ch[0]), max_height(root->ch[1])) + 1;
}

int main() {
    Mem = new node[Max_Node];
    init();
    node* root = null;
    for(int i = 0; i < Max_Node; i++) insert(root, rand());
    cout<<"5*10^7 height:"<<max_height(root)<<endl;
    for(int i = 0; i < Max_Node - 100000; i++) del(root, i);
    cout<<"10^5 height:"<<max_height(root)<<endl;
}

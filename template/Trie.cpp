#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
struct node {
    bool next[256];
    node() {
        for(int i = 0; i < 256; i++) {
            next[i] = 0;
        }
    }

};
struct Trie {
    node* root;
    Trie() {
        root = new node();
    }

    void add(int a[]) {
        node* temp = root;
        for(int i = 0; i < 4; i++) {
            if(temp->next[a[i]] == NULL) {
                temp -> next[a[i]] = new node();
                cnt++;
                if(cnt % 10000 == 0) cout<<cnt<<endl;
            }
            temp = temp -> next[a[i]];
        }
    }
} trie;
int main() {
    int ip[4];
    long long x = 0;
    for(int i = 0; i < 1; i++) {
        ip[0] = i;
        for(int j = 0; j < 10; j++) {
            ip[1] = j;
            for(int k = 0; k < 256; k++) {
                ip[2] = k;
                for(int l = 0; l < 256; l++) {
                    ip[3] = l;
                    trie.add(ip);
                }
            }
        }
    }
    cin >> x;
}

#include <bits/stdc++.h>

using namespace std;
map<int, string> Fname;
struct node {
    node* next[10];
    int name;
    node() {
        memset(next, 0, sizeof next);
        cout<< sizeof(next) << endl;
    }
};

int main() {
    node*root=new node();
}

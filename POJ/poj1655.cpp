#include <stdio.h>
#include <algorithm>

using namespace std;
const int N = 22222;
struct node {
    int to; node* next;
} edge[N*2], *G[N];
int ptr = 0, son[N], n, ans, size = ~0U>>1; bool vis[N];
void add(int a, int b) { edge[ptr].to = b; edge[ptr].next = G[a]; G[a] = &edge[ptr++];} 
void init() {size = ~0U>>1;ptr = 0; memset(G, 0, sizeof(node*) * N); memset(vis, 0, sizeof vis); }
void dfs(int cur) {
    vis[cur] = true;
    son[cur] = 0;
    int t = 0;
    for(node* temp = G[cur]; temp; temp = temp->next) {
        int to = temp->to;
        if(!vis[to]) {
            dfs(to);
            son[cur] += son[to] + 1;
            t = max(t, son[to] + 1);
        }
    }
    t = max(t, n - son[cur] - 1);
    if(t < size || (t == size && cur < ans)) {
        ans = cur;
        size = t;
    }
}
int main() {
    int _; scanf("%d", &_);
    while(_--) {
        init();
        scanf("%d", &n);
        int a, b;
        for(int i = 1; i < n; i++) { scanf("%d%d", &a, &b); add(a, b); add(b, a);} 
        dfs(1);
        printf("%d %d\n", ans, size);
    }
}

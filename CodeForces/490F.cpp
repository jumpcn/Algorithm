#include <bits/stdc++.h>

using namespace std;
const int N = 6e3 +10;
const int inf = ~0U>>1;
vector<int> G[N];
int r[N], d[N], ans = 0;

void dfs(int v, int p) {
    auto it = lower_bound(d, d + N, r[v]);
    int tmp = *it;
    *it = r[v];
    ans = max(ans, lower_bound(d, d + N, inf) - d - 1);
    for(auto y : G[v]) if(y != p) dfs(y, v);
    *it = tmp;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", r + i);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        G[n].push_back(i);
    }
    fill(d, d + N, inf);
    dfs(n, -1);
    printf("%d\n", ans);
}

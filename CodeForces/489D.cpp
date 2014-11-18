#include <bits/stdc++.h>

using namespace std;


const int N = 3333;

bool d[N][N];

vector<vector<int>> G;

int main() {
    int n, m;
    cin >> n >> m;
    G.resize(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        d[a][b] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            int c = 0;
            for(int k = 0; k < G[i].size(); k++) {
                if(G[i][k] != j && G[i][k] != i && d[G[i][k]][j]) c++;
            }
            ans += c * (c - 1) / 2;
        }
    }
    cout << ans;
}

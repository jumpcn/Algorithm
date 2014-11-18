#include <bits/stdc++.h>

using namespace std;
vector<int> b, g;
int main() {
    int n, m, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        b.push_back(a);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a;
        g.push_back(a);
    }

    int ans = 0, idx1 = 0, idx2 = 0;

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    while(idx1 < b.size() && idx2 < g.size()) {
        int k = b[idx1];
        if(g[idx2] - k > 1) {
            idx1++;
        } else if(g[idx2] - k < -1) {
            idx2++;
        } else {
            ans++;
            idx1++;
            idx2++;
        }
    }
    cout << ans << endl;
}

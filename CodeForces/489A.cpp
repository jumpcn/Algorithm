#include <bits/stdc++.h>
using namespace std;

const int N = 3333;
int d[N];
int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vector<pair<int, int>> ans;

    d[0] = ~0U >> 1;

    for(int i = 1; i < n; i++) {
        int idx = 0, val = 0;
        val = d[i];
        for(int j = i + 1; j <= n; j++) {
            if(d[j] < val) {
                val = d[j];
                idx = j;
            }
        }
        if(idx != 0) {
            swap(d[i], d[idx]);
            ans.push_back(make_pair(i - 1, idx - 1));
        }
    }

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

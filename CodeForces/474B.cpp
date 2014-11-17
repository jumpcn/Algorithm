#include <bits/stdc++.h>

using namespace std;

const int N = 111111;

int d[N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    int a, q;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> a;
        cout << lower_bound(d + 1, d + 1 + n, a) - d << endl;
    }
}

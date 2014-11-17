#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL MOD = 1e9 + 7;
const int N = 1e5 + 5;

LL dp[N], sum[N];
int main() {
    int t, k, a, b, q;
    cin >> q >> k;
    for(int i = 1; i < N; i++) {
        dp[i]++;
        sum[i] = sum[i - 1] + dp[i];
    }
    dp[k]++; sum[k]++;

    for(int i = k + 1; i < N; i++) {
        dp[i] = dp[i - k] + dp[i - 1];
        dp[i] %= MOD;
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= MOD;
    }

    while(q--) {
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1] + MOD) % MOD << endl;
    }
}

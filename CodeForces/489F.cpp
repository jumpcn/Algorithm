#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 555;

LL dp[N][N], MOD, h[N];
int n, m;
char d[N];

int main() {
    cin >> n >> m >> MOD;

    for(int i = 1; i <= m; i++) {
        cin >> d;
        for(int j = 0; j < n; j++) {
            h[j] = d[j] == '1';
        }
    }
    int d0 = 0, d1 = 0;

    for(int i = 0; i < n; i++) {
        if(h[i] == 0) d0++;
        else d1++;
    }

    dp[d0][d1] = 1;


}

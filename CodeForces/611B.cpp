#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

LL a, b;
int ans = 0;

void dfs(LL x, int zero) {
    if(x > b) return;
    if(a <= x && x <= b && zero == 1) ans++;
    if(zero == 0) dfs(x * 2, zero + 1);
    dfs(x * 2 + 1, zero);
}

int main() {
    cin >> a >> b;
    dfs(1, 0);
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

void dfs(int a) {
    if(a == 0) return;
    dfs(a >> 1);
    cout << (a & 1);
}

int main() {
    int a;
    while(cin >> a) {
        if(a < 0) return -1;
        else if(a == 0) cout << 0 << endl;
        else {
            dfs(a);
            cout << endl;
        }
    }
}

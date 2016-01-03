#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[11] = {0};
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1; j <= m; j++) {
            if(i != j) ans += a[i] * a[j];
        }
    }

    cout << ans << endl;
}

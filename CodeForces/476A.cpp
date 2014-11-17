#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = n % 2 + n / 2;
    while(ans <= n) {
        if(ans % m == 0) {
                cout << ans << endl;
                return 0;
        }
        ans++;
    }
    cout<<-1<<endl;
}

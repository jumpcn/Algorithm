#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int solve(LL a) {
    int step = 1;
    while(true) {
        LL k = a + step;
        k = abs(k);
        bool find = false;
        while(k) {
            if(k % 10 == 8) {
                find = true;
                break;
            }
            k /= 10;
        }
        if(find) break;
        ++step;
    }
    return step;
}
int main() {
    LL a;
    cin >> a;
    cout << solve(a) << endl;
}

#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int h[N], a[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    h[a[0]]++;
    int s = 1, x = 0;
    for(int i = 1; i < n; i++) {
        if(h[a[i]] == 0) s++;
        h[a[i]]++;
        while(s > k) {
            --h[a[x]];
            if(h[a[x]] == 0) s--;
            ++x;
        }
        if(i - x > r - l) r = i, l = x;
    }
    cout << l + 1 << " " << r + 1 << endl;
}

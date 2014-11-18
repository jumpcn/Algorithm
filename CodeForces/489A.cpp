#include <bits/stdc++.h>
using namespace std;

const int N = 3333;
int d[N];
int main() {
    int n;
    cin >> n;
    int* k = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        k[i] = d[i];
    }

    sort(d, d + n);
}

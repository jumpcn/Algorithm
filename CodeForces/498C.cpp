#include <bits/stdc++.h>

using namespace std;

vector<int> digit;
int main() {
    int n, m;
    cin >> n >> m;
    if(n * 9 < m) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    digit.resize(n, 9);

    int sum = n * 9 - m;
    for(auto& i : digit) {
        if(sum >= 8) {
            i -= 8;
            sum -= 8;
        } else {
            i -= sum;
            sum = 0;
        }
        if(sum == 0) break;
    }

    for(auto& i : digit) {
        cout<<i;
    }
    cout << " ";
    for(int i = digit.size() - 1; i >= 0; i--) {
        cout<<digit[i];
    }
    cout<<endl;
}

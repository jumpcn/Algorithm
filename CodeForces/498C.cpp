#include <bits/stdc++.h>

using namespace std;

vector<int> digit;
int main() {
    int n, m;
    cin >> n >> m;
    if(n * 9 < m || m == 0) {
        if(m == 0 && n == 1) {
            cout<< 0 << " " << 0 << endl;
            return 0;
        }
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    digit.resize(n, 9);
    int sum = n * 9 - m;
    for(int i = 0; i < n; i++) {
        if(i == 0 && sum) {
            if(sum >= digit[i] - 1) {
                sum -= (digit[i] - 1);
                digit[i] = 1;
            } else {
                digit[i] -= sum;
                sum = 0;
            }
        } else if (sum > 0) {
            if(sum >= 9) {
                digit[i] = 0;
                sum -= 9;
            } else {
                digit[i] -= sum;
                sum = 0;
            }
        }
        cout<<digit[i];
    }

    cout << " ";
    digit.clear();
    digit.resize(n, 9);
    sum = n * 9 - m;
    for(auto& i : digit) {
        if(sum >= 9) {
            i -= 9;
            sum -= 9;
        } else {
            i -= sum;
            sum = 0;
        }
        if(sum == 0) break;
    }
    reverse(digit.begin(), digit.end());
    for(auto& i : digit) {
        cout<<i;
    }
    cout<<endl;
}

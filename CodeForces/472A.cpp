#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i = 2; i <= (sqrt(x * 1.0) + 1); i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n - 2; i++) {
        if(!isPrime(i) && !isPrime(n - i)) {
            cout << i << " " << n - i << endl;
            return 0;
        }
    }
}

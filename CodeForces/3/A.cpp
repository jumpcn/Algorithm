#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int s = a[0] - b[0];
    int e = a[1] - b[1];
    cout << max(abs(s), abs(e)) << endl;
    while(s != 0 || e != 0) {
        if(s > 0) cout << "L", s--;
        if(s < 0) cout << "R", s++;
        if(e > 0) cout << "D", e--;
        if(e < 0) cout << "U", e++;
        cout << endl;
    }
}

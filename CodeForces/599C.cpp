#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v1, v2;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v1.push_back(a);
        v2.push_back(a);
    }
    sort(v2.begin(), v2.end());
    map<int, int> s1, s2;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        s1[v1[i]]++;
        s2[v2[i]]++;
        if(s1 == s2) {
            ans++;
            s1.clear(); s2.clear();
        }
    }
    cout << ans << endl;
}

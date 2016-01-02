#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n ,&k);
    vector<pair<int,int>> vp;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a ,&b);
        vp.push_back(make_pair(a, 0));
        vp.push_back(make_pair(b, 1));
    }
    sort(vp.begin(), vp.end());

    int f = 0;
    for(int i = 0; i < vp.size(); i++) {
        if(vp[i].second == 0) {
            f++;
            if(f == k) ans.push_back(vp[i].first);
        } else {
            if(f == k) ans.push_back(vp[i].first);
            f--;
        }
    }

    printf("%d\n", ans.size() / 2);
    for(int i = 0; i < ans.size(); i+=2) printf("%d %d\n", ans[i], ans[i+1]);
}

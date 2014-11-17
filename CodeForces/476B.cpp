#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int len = s1.size();

    int f1 = 0, f2 = 0, cnt = 0;
    for(int i = 0; i < len; i++) {
        f1 += s1[i] == '+' ? 1 : -1;
    }

    for(int i = 0; i < len; i++) {
        switch(s2[i]) {
            case '+': f2++; break;
            case '-': f2--; break;
            case '?': cnt++; break;
        }
    }
    double ans = 0.;
    if(cnt == 0) {
        ans = f1 == f2 ? 1 : 0;
    } else {
        int L = abs(f1 - f2);
        if(L > cnt) ans = 0;
        else {
            int tot = 0;
            for(int i = 0; i < (1 << cnt); i++) {
                int t = 0;
                for(int j = 0; j < cnt; j++) {
                    if(i & (1<<j)) t++;
                    else t--;
                }
                if(t == L) tot++;
            }
            ans = tot * 1.0 / (1 << cnt);
        }
    }
    printf("%.9f\n", ans);
}

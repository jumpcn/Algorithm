#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int MOD[N]= {0};

char str[N];
int main() {
    cin >> str;
    int a, b;
    cin >> a >> b;
    int len = strlen(str);

    int k = 1;
    for(int i = len - 1; i >= 0; i--) {
        MOD[i] = (MOD[i+1] + k * (str[i] - '0')) % b;
        k = k * 10 % b;
    }

    k = 0;
    for(int i = 0; i < len - 1; i++) {
        k = (k * 10 + str[i] - '0') % a;
        if(k == 0 && MOD[i + 1] == 0 && str[i + 1] != '0') {
            cout<<"YES"<<endl;
            for(int x = 0; x <= i; x++) putchar(str[x]);
            cout<<endl;
            for(int x = i + 1; x < len; x++) putchar(str[x]);
            return 0;
        }
    }
    cout << "NO" << endl;
}

#include <bits/stdc++.h>
using namespace std;
char a[3][11] = {
    "qwertyuiop",
    "asdfghjkl;",
    "zxcvbnm,./"
};

char _index(char k, int op) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 10; j++) {
            if(a[i][j] == k) {
                return a[i][j+op];
            }
        }
    }
}
char in[111];
int main() {
    int op; char f;
    cin >> f;
    op = f == 'R' ? -1 : 1;
    cin >> in;
    int len = strlen(in);
    for(int i = 0; i < len; i++) {
        cout<<_index(in[i], op);
    }
}

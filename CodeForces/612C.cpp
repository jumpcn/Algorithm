#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getOp(char s) {
    switch(s) {
        case '[': return 1;
        case ']': return -1;
        case '{': return 2;
        case '}': return -2;
        case '<': return 3;
        case '>': return -3;
        case '(': return 4;
        case ')': return -4;
    }
    return 0;
}
int main() {
    string s;
    cin >> s;
    stack<int> st;
    int sz = s.size(), ans = 0;
    for(int i = 0; i < sz; i++) {
        int op = getOp(s[i]);
        if(op > 0) st.push(op);
        else {
            if(st.empty()) {ans = -1; break;}
            if(op + st.top() != 0) ans++;
            st.pop(); 
        }
    }
    if(!st.empty() || ans < 0) cout << "Impossible" << endl;
    else cout << ans << endl;
}

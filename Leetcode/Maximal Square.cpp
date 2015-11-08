typedef long long ll;
struct node {
    ll h; int l;
    node(ll a, int b) {
        h = a;
        l = b;
    }
};

int maxR(vector<int> &num) {
boo = false;
    if(num.size() == 0) return 0;
    stack<node> st;
    num.push_back(-1);
    st.push(node(num[0], 1));
    ll ans = 0;
    for(int i = 1; i <= num.size(); i++) {
        ll h = num[i];
        if(h >= st.top().h) {
            st.push(node(h, 1));
        } else {
            ll l = 0;
            while(!st.empty() && h < st.top().h) {
                l += st.top().l;
                ans = max(ans, min(l, st.top().h));
                st.pop();
            }
            st.push(node(h, l + 1));
        }
    }
    return ans;
}
class Solution {
public:
    int maximalSquare(vector<vector<char> > &m) {
        int sz = m.size();
        if(sz == 0) return 0;
        int ans = 0;
        vector<int> h;
        h.resize(m[0].size());
        fill(h.begin(), h.end(), 0);
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < m[i].size(); j++) {
                if(m[i][j] == '0') h[j] = 0;
                else h[j]++;
            }
            ans = max(ans, maxR(h));
        }
        return ans * ans;
    }
};




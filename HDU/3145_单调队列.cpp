#include <cstdio>
#include <queue>
using namespace std;
const int inf = (~0U>>1);
int data[200002];
int main() {
    int cas, n, k;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d", &n, &k);
        data[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", data + i);
            data[i] += data[i-1];
        }
        for(int i = n + 1; i < n + k; i++) {
            data[i] = data[n] + data[i - n];
        }
        int tot = n + k - 1;
        int st, ed, maxn = -inf;
        deque<int> q;
        for(int i = 1; i <= tot; i++) {
            while(!q.empty() && data[i-1] < data[q.back()]) q.pop_back();
            q.push_back(i-1);
            while(!q.empty() && i - q.front() > k) q.pop_front();
            if(maxn < data[i] - data[q.front()]) {
                maxn = data[i] - data[q.front()];
                st = q.front() + 1;
                ed = i > n ? i - n : i;
            }
        }
        printf("%d %d %d\n", maxn, st, ed);
    }
}

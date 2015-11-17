#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 55555;
struct edge{ int x, y, c;} T[N];
bool cmp(edge& x, edge& y) { return x.c > y.c;}
int n, m, r, x, y, d;
int F[N];
int U(int x) {return F[x] = (F[x] == x ? x : U(F[x]));}
int main() {
    int cas; scanf("%d", &cas);
    for(int _ = 0; _ < cas; _++) {
        scanf("%d%d%d", &n, &m, &r);
        for(int i = 0; i < r; i++) {
            scanf("%d%d%d", &T[i].x, &T[i].y, &T[i].c);
        }
        for(int i = 0; i <= n + m; i++) F[i] = i; 
        sort(T, T + r, cmp);
        int ans = 0;
        for(int i = 0; i < r; i++) {
            int fx = U(T[i].x);
            int fy = U(T[i].y + n);
            if(fx!=fy) { F[fx] = fy; ans += T[i].c;}
        }
        printf("%d\n",  (n + m) * 10000 - ans);
    }
}


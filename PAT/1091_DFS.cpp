#include <cstdio>
#include <queue>
using namespace std;

struct node { //bfs过程中需要记录的节点
    int x, y, z;
    node(int a, int b, int c) : x(a), y(b), z(c) {} //构造函数
};
int n, m, slice, T;
int pixel[1290][130][61]; //这里数组稍微开大一点，分别对应坐标的x,y,z
int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0}; //{X[i], Y[i], Z[i]}代表增量方向

void dfs(int z, int x, int y, int& tot) {
    pixel[x][y][z] = 0;
    tot++;
    for(int i = 0; i < 6; i++) {
        int newX = x + X[i];
        int newY = y + Y[i];
        int newZ = z + Z[i];
        if(newX > n || newX < 0 || newY > m || newY < 0 || newZ > slice || newZ < 0) continue;
        else if(pixel[newX][newY][newZ] == 0) continue;
        else {
            dfs(newZ, newX, newY, tot);
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &pixel[j][k][i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(pixel[j][k][i] == 1) {
                    int tot = 0;
                    dfs(i, j, k, tot);
                    if(tot >= T) ans += tot;
                }
            }
        }
    }
    printf("%d\n", ans);
}

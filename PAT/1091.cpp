#include <cstdio>
#include <queue>
using namespace std;


struct node { //bfs过程中需要记录的节点
    int x, y, z;
    node(int a, int b, int c) : x(a), y(b), z(c) {} //构造函数
};
int n, m, slice, T;
bool pixel[1290][130][61]; //这里数组稍微开大一点，分别对应坐标的x,y,z
int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0}; //{X[i], Y[i], Z[i]}代表增量向量

int bfs(int z, int x, int y) {
    queue<node> Q;
    Q.push(node(x, y, z));
    pixel[x][y][z] = 0;
    int tot = 1;
    while(!Q.empty()) {
        node temp = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++) { //循环六次，得到六个增量方向
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            int newZ = temp.z + Z[i];
            if(newX > n || newX < 0 || newY > m || newY < 0 || newZ > slice || newZ < 0) continue; //如果越界则不处理
            else if(pixel[newX][newY][newZ] == 0) continue; //如果不是脑残点，也忽略
            else {
                tot++; //脑残点加以
                pixel[newX][newY][newZ] = 0; //赋值为0表示记录过
                Q.push(node(newX, newY, newZ)); //加入队列
            }
        }
    }
    if(tot >= T) return tot; //如果超过阈值则返回
    else return 0; //否则不记录
}
int main() {
    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &pixel[j][k][i]); //注意这里的读入是z轴开始
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(pixel[j][k][i] == 1) {
                    ans += bfs(i, j, k); //还是循环的方向
                }
            }
        }
    }
    printf("%d\n", ans);
}

#include <cstdio>
#include <queue>
using namespace std;


struct node { //bfs��������Ҫ��¼�Ľڵ�
    int x, y, z;
    node(int a, int b, int c) : x(a), y(b), z(c) {} //���캯��
};
int n, m, slice, T;
bool pixel[1290][130][61]; //����������΢����һ�㣬�ֱ��Ӧ�����x,y,z
int X[] = {0, 0, 0, 0, 1, -1};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {1, -1, 0, 0, 0, 0}; //{X[i], Y[i], Z[i]}������������

int bfs(int z, int x, int y) {
    queue<node> Q;
    Q.push(node(x, y, z));
    pixel[x][y][z] = 0;
    int tot = 1;
    while(!Q.empty()) {
        node temp = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++) { //ѭ�����Σ��õ�������������
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            int newZ = temp.z + Z[i];
            if(newX > n || newX < 0 || newY > m || newY < 0 || newZ > slice || newZ < 0) continue; //���Խ���򲻴���
            else if(pixel[newX][newY][newZ] == 0) continue; //��������Բе㣬Ҳ����
            else {
                tot++; //�Բе����
                pixel[newX][newY][newZ] = 0; //��ֵΪ0��ʾ��¼��
                Q.push(node(newX, newY, newZ)); //�������
            }
        }
    }
    if(tot >= T) return tot; //���������ֵ�򷵻�
    else return 0; //���򲻼�¼
}
int main() {
    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &pixel[j][k][i]); //ע������Ķ�����z�Ὺʼ
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < slice; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(pixel[j][k][i] == 1) {
                    ans += bfs(i, j, k); //����ѭ���ķ���
                }
            }
        }
    }
    printf("%d\n", ans);
}

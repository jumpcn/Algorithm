#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005;
vector<int> G[N];  //储存图G的vector

int maxHeight = 0; //最大高度
int Ans = 0; //最大高度的个数
void dfs(int root, int height) {
    if(G[root].size() == 0) { //没有儿子节点就是说明到根了
        if(height == maxHeight) {
            Ans++; //如果和最大高度一样，答案加一
        } else if (height > maxHeight) { //如果大于最大答案
           maxHeight = height; //更新答案
           Ans = 1; //这里的答案是1不是0
        }
        return;
    }
    for(int i = 0; i < G[root].size(); i++) {
        dfs(G[root][i], height + 1); //往儿子节点递归
    }
}

int main() {
    int n, fa, root;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &fa);
        if(fa == -1) {
            root = i;
            continue;
        }
        G[fa].push_back(i); //这里要搞清楚方向
    }
    dfs(root, 0);
    printf("%.2lf %d\n", p * pow((1 + r / 100.0), maxHeight), Ans);
}

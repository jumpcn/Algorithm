#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int max_node = 1111;
int n, m, k, q, getQuery;
int convertToMinute(int h, int m) {
    return h * 60 + m; //转换时间为分钟，方便时间处理
}
struct Window {
    int endTime, popTime; //对于一个窗口来说，有对于当前队伍所有在队的人的处理总时间endTime和在队头人处理完走人的的popTime
    queue<int> q;
    Window() {
        popTime = endTime = convertToMinute(8, 0);
    }
} window[20];
int ans[max_node], needTime[max_node];
int main() {
    int inIndex = 0;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++) {
        ans[i] = -1; //首先将答案数组赋值为-1
        scanf("%d", &needTime[i]); //读入需要处理的时间
    }
    for(int i = 0; i < min(n * m, k); i++) { //这里有一个坑的地方在于k可能大于 n * m，这样就队排满了
        window[inIndex % n].q.push(inIndex); //对n取余用来循环排队
        window[inIndex % n].endTime += needTime[inIndex]; //对于这个窗口的处理结束的时间要加上这个来的人的需要时间
        ans[inIndex] = window[inIndex % n].endTime; //对于inIndex的人来说处理完的时间就是当前窗口处理完的时间
        inIndex++;
    }
    for(; inIndex < k; inIndex++) {
        int idx = -1, minPopTime = 1 << 30; //minPopTime是最早弹出时间，这里要找到所有窗口的最短时间，这样人才能跟上去
        for(int i = 0; i < n; i++) { //找呀找呀找呀找
            Window& W = window[i];
            if(W.popTime + needTime[W.q.front()] < minPopTime) {
                idx = i; //找到了！
                minPopTime = W.popTime + needTime[W.q.front()]; //更新
            }
        }
        if(idx != -1) { //更新endTime和popTime
            Window& W = window[idx];
            W.endTime += needTime[inIndex];
            W.popTime += needTime[W.q.front()];
            W.q.pop();
            W.q.push(inIndex);
            ans[inIndex] = W.endTime; //获得答案
        } else break;
    }
    for(int i = 0; i < q; i++) {
        scanf("%d", &getQuery);
        if(ans[getQuery - 1] == -1 || ans[getQuery - 1] - needTime[getQuery - 1] >= convertToMinute(17, 0)) printf("Sorry\n");
        else printf("%02d:%02d\n", ans[getQuery - 1] / 60, ans[getQuery - 1] % 60);
    }
}

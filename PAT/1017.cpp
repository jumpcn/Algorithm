#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 111;
const int inf = 1111111111;
struct Customer {
    int come, server;
    Customer(int _come, int _server) {
        come = _come;
        server = _server >= 3600 ? 3600 : _server; //最多服务3600秒，一个小时
    }
};
vector<Customer> custom;
int convertTime(int h, int m, int s) {
    return h*3600+m*60+s;  //时间转换为秒，方便处理
}
bool cmp(Customer a, Customer b) {
    return a.come < b.come; //按照来的时间来排序
}
int startTime[K]; //窗口能够开始下一次服务的时间
int main() {
    int c, w, totTime = 0;
    int stTime = convertTime(8, 0, 0); //开始时间在一天的秒数
    int edTime = convertTime(17, 0, 0); //结束时间在一天秒数
    scanf("%d%d", &c, &w);
    for(int i = 0; i < w; i++) startTime[i] = stTime; //开始没有顾客，所以开始的时间就是8:00
    for(int i = 0; i < c; i++) {
        int h, m, s, server;
        scanf("%d:%d:%d %d", &h, &m, &s, &server); //读入顾客信息
        int comeTime = convertTime(h, m, s); //转换开始时间
        if(comeTime > edTime) continue; //如果来的比关门时间还晚，放弃
        custom.push_back(Customer(comeTime, server * 60)); //放到顾客vector
    }
    sort(custom.begin(), custom.end(), cmp); //按照时间排序
    for(int i = 0; i < custom.size(); i++) {
        int idx = -1, t = inf; //idx表示的是能够服务的窗口的下标,t的用处是为了找到能最早服务这个顾客的时间
        for(int j = 0; j < w; j++) {
            if(startTime[j] >= custom[i].come && startTime[j] < t) {
                t = startTime[j];//找到一个能服务的，那么就更新他的服务时间，找到一个最小的
                idx = j;
            }
        }
        totTime += (startTime[idx] - custom[i].come); //开始处理这个顾客的服务时间
        startTime[idx] += custom[i].server; //这个窗口下次能服务的时间自然是开始服务时间+这个顾客需要的时间
    }
    printf("%.1f\n", custom.size() == 0 ? 0 : totTime * 1.0 / 60 / custom.size());
    return 0;
}

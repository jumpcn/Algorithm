#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U>>1;
struct LoserTree {
    int* cur;
    int* tree;
    int N;
    int curN;
    vector<vector<int>> data;
    LoserTree() {}
    LoserTree(vector<vector<int>>& a) {
        data = a;
        curN = N = a.size();
        tree = new int[N * 2 + 1];
        cur = new int[N + 1];
        fill(cur, cur + N + 1, 0);
        for(int i = 0; i < N; i++) tree[i + N] = i;
        for(int i = 1; i < N; i++) {
            int id = N - i;
            int left = id * 2;
            int right = left + 1;
            if(data[tree[left]][0] < data[tree[right]][0]) {
                tree[id] = tree[left];
            } else tree[id] = tree[right];
        }
   //     for(int i = 1; i < N * 2; i++) cout << tree[i] << " "; cout << endl;
        Merge();

    }

    void Merge() {
        cout << "Merge Begin:" << endl;
        int loser = tree[1];
        while(curN) {
            cout << data[loser][cur[loser]] << " ";
            if(cur[loser] == data[loser].size() - 1) {
                curN--;
                data[loser][data[loser].size() - 1] = inf;
                adjust(loser);
            } else {
                cur[loser] += 1;
                adjust(loser);
            }
            loser = tree[1];
        }
        cout << endl;
    }

    void adjust(int d) {
        d = N + d;
        while(d != 1) {
            d /= 2;
            int left = d * 2;
            int right = left + 1;
            int leftId = tree[left];
            int rightId = tree[right];
            if(data[leftId][cur[leftId]] < data[rightId][cur[rightId]]) {
                tree[d] = leftId;
            } else tree[d] = rightId;
        }
    }
};

vector<vector<int>> vi;
vector<int> ALL;
void init(vector<vector<int>>& vii) {
    for(int i = 0; i < 5; i++) {
        vector<int> t;
        int sz = rand() % 10 + 1;
        for(int j = 0; j < sz; j++) {
            int temp = rand();
            temp = (rand()&1?1:-1)* temp;
            ALL.push_back(temp);
            t.push_back(temp);
        }
        sort(t.begin(), t.end());
        vii.push_back(t);
    }
}
int main() {
    srand(time(0));
    init(vi);
    LoserTree lt(vi);
    sort(ALL.begin(), ALL.end());
    cout << "Compare to Original: " << endl;
    for(auto i : ALL) cout << i <<" "; cout << endl;
}

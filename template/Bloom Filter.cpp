#include <bits/stdc++.h>

using namespace std;
const int N = 200000000;
const int M = 10000000;
const int K = 14;
int total = 10000000;
bool bits[N];
long long h[30];

int BFinsert(int x) {
    for(int i = 0; i < K; i++) {
        bits[int(1LL * x * h[i] % N)] = true;
    }
}
bool BFfind(int x) {
    for(int i = 0; i < K; i++) {
        if(!bits[int(1LL * x * h[i] % N)]) return false;
    }
    return true;
}
vector<int> vi;
unordered_set<int> usi;

int main() {
    h[0] = 1; h[1] = 1;
    for(int i = 2; i < 30; i++) h[i] = h[i-1] + h[i-2];
    srand(time(0));

    for(int i = 0; i < M; i++) {
        int t = rand() * rand();
        if(t < 0) t = -t;
        BFinsert(t);
        vi.push_back(t);
        usi.insert(t);
    }

    int error = 0;

    for(int i = 0; i < total; i++) {
        int t = rand();
        if(BFfind(t) == true && usi.count(t) == 0) error++;
    }
    cout << "total:" << total << endl;
    cout << "error:" << error << endl;
    cout << error * 1.0 / total * 100 << "%" << endl;

}

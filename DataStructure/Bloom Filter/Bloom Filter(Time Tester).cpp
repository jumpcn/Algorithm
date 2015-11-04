#include <bits/stdc++.h>

using namespace std;
const int N = 200000000;
const int M = 10000000;
const int K = 15;
int total = 10000000;
bool bits[N];
long long  h[30];
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
        int t = i;
        if(t < 0) t = -t;
        vi.push_back(t);
    }
    cout<<"heh"<<endl;
    int error = 0;
    long long tt = clock();
    for(int i = 0; i < M; i++) {
        BFinsert(vi[i]);
    }
    for(int i = 0; i < M; i++) {
        BFfind(vi[i]);
    }
    cout << "BFTime:" << clock() - tt << endl;
    tt = clock();
    for(int i = 0; i < M; i++) {
    //    usi.insert(vi[i]);
    }
    for(int i = 0; i < M; i++) {
   //     usi.count(vi[i]);
    }
    cout << "HashTime:" << clock() - tt << endl;
    int a; cin >> a;
    for(int i = 0; i < M; i++) usi.count(vi[i]);

}


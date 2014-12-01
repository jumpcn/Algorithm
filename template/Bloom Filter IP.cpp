#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 150000000;
const int M = 10000000;
const int K = 11;
int total = 1000000;
bool bits[N];
LL h[30];
struct IP {
    LL ip[4];
    IP() {}
    IP (int a, int b, int c, int d) {
        ip[0] = a; ip[1] = b; ip[2] = c; ip[3] = d;
    }
    friend bool operator < (const IP& a, const IP& b) {
        for(int i = 0; i < 4; i++) {
            if(a.ip[i] == b.ip[i]) continue;
            else return a.ip[i] < b.ip[i];
        }
        return false;
    }
};
LL  reflectHash(IP& a) {
    LL ans = 0;
    for(int i = 0; i < 4; i++) {
        ans |= (a.ip[i] << ((i) * 8));
    }
    return ans;
}


int BFinsert(IP& x) {
    LL code = reflectHash(x);
    for(int i = 0; i < K; i++) {
       // cout<<code <<" "<< code * h[i] << endl;
        bits[int(1LL * code * h[i] % N)] = true;
    }
}
bool BFfind(IP& x) {
    LL code = reflectHash(x);
    for(int i = 0; i < K; i++) {
        if(!bits[int(1LL * code * h[i] % N)]) return false;
    }
    return true;
}
vector<IP> vi;
set<IP> usi;

int main() {
    h[0] = 1; h[1] = 1;
    for(int i = 2; i < 30; i++) h[i] = h[i - 1] + h[i - 2];
    srand(time(0));
    for(int i = 0; i < M; i++) {
        IP temp = IP(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    //    vi.push_back(temp);
        usi.insert(temp);
        BFinsert(temp);
    }

    int error = 0;

    for(int i = 0; i < total; i++) {
        IP t = IP(rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        if(BFfind(t) == true && usi.count(t) == 0) error++;
    }
    cout << "total:" << total << endl;
    cout << "error:" << error << endl;
    cout << error * 1.0 / total * 100 << "%" << endl;

}



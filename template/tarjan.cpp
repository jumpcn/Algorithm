#include <iostream>
#include <stack>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int MAXM = 500000 + 10;


struct EDGE {
	int v;
	int next;
};

stack<int> s;
EDGE edge[MAXM];
int low[MAXN];
int dfn[MAXN];
int first[MAXN];
int sccf[MAXN];
bool ins[MAXN];
int outdegree[MAXN];
int index;
int scc;
int n, m;


void Init() {
	scc = 0;
	index = 1;
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(ins, false, sizeof(ins));
	memset(sccf, 0, sizeof(sccf));
	memset(first, -1, sizeof(first));
}

void Tarjan(int u) {
	int v;
	low[u] = dfn[u] = index++;
	s.push(u);
	ins[u] = true;
	for (int k = first[u]; k != -1; k = edge[k].next) {
		v = edge[k].v;
		if (dfn[v] == 0) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		scc++;
		do {
			v = s.top();
			s.pop();
			ins[v] = false;
			sccf[v] = scc;
		} while (u != v);
	}
}


map<string, int> Map;
map<int, string> GName;
bool cmp1(int i, int j) {
    return GName[i] < GName[j];
}

bool cmp2(const vector<int>& a1, const vector<int>& a2) {
    return GName[*a1.begin()] < GName[*a2.begin()];
}
int main() {
	freopen("d:\\data.txt", "r", stdin);
	int i, u, v;
	int e = 0;
	GName.clear();
	Init();
	string n, m;
	int idx = 0;
	while (cin >> n >> m) {
		int a, b;
		if (Map.find(n) == Map.end()) {
			Map[n] = ++idx;
			GName[idx] = n;
		}
		if (Map.find(m) == Map.end()) {
			Map[m] = ++idx;
			GName[idx] = m;
		}
		a = Map[n];
		b = Map[m];
		edge[e].v = b;
		edge[e].next = first[a];
		first[a] = e;
		e++;
	}

	for (i = 1; i <= idx; i++) {
		if (dfn[i] == 0) {
			Tarjan(i);
		}
	}
	// cout << GetSuperPopularNum() << endl;
	vector<vector<int>> ans;
	ans.resize(scc);
	for (i = 1; i <= idx; i++) {
		ans[sccf[i] - 1].push_back(i);
	}
	for(int i = 0; i < scc; i++) {
        sort(ans[i].begin(), ans[i].end(), cmp1);
	}
	sort(ans.begin(), ans.end(), cmp2);
	for (int i = 0; i < scc; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			if (j == 0) cout << GName[ans[i][j]];
			else cout << " " << GName[ans[i][j]];
		}
		if (i != scc - 1) cout << endl;
	}
	return 0;
}




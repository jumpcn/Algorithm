#include <iostream>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;
//0 divisor
//1 +
//2 -
int main() {
	int sum;
	int T[9];
	while (cin >> sum) {
		clock_t start_time = clock();
		int Ans = 0;
		for (int i = 0; i < 256; i++) {
			vector<int> s;
			vector<int> f;
			int k = i;
			for (int d = 1; d <= 8; d++) {
				T[d] = k % 2;
				k /= 2;
				if (T[d] == 0) f.push_back(d);
			}
			if (f.size() == 0) {
				if (sum == 123456789) {
					Ans++;
				}
				continue;
			}
			int pre = 0;
			int curNum = 0;
			for (int d = 0; d < f.size(); d++) {
				for (; pre <= f[d]; pre++) {
					curNum = curNum * 10 + pre;
				}
				s.push_back(curNum);
				curNum = 0;
				pre = f[d] + 1;
			}
			for (; pre <= 9; pre++) {
				curNum = curNum * 10 + pre;
			}
			s.push_back(curNum);


			//for (int d = 0; d < s.size(); d++) cout << s[d] << " "; cout << endl;
			//for (int d = 1; d <= 8; d++) if (T[d] == 1 || T[d] == 2) cout << T[d] <<" "; cout << endl;
			int K = s.size() - 1;
			for (int p = 0; p < ((1 << K) - 1); p++) {
				stack<int> num;
				for (int d = s.size() - 1; d >= 0; d--) {
					num.push(s[d]);
				}
				for (int x = 0; x < K; x++) {
					if ((p & (1 << x)) == 0) {
						int a = num.top(); num.pop();
						int b = num.top(); num.pop();
						num.push(a + b);
					}
					else {
						int a = num.top(); num.pop();
						int b = num.top(); num.pop();
						num.push(a - b);
					}
				}
				if (num.top() == sum) {
					Ans++;
				}
			}


		}
		cout << Ans << endl;
		cout << clock() - start_time << endl;
	}
}

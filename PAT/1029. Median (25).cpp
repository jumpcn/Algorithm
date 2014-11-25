#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int lim = 333; //设定一个大于根号100000的数字
stack<int> st;
int size, a, q;
char cmd[20];
int bucket[lim]; // 放的是每个桶所容纳的数量，每个桶所记录的是每个lim区间所容纳的元素个数
int table[100005]; //简单hash表的用处是来记录这个数字的数量
int main() {
	for (int i = 0; i < 100005; i++)table[i] = 0; //初始化简单hash表
	for (int i = 0; i < lim; i++) bucket[i] = 0; //初始化桶
	scanf("%d", &q);
	while (q--) {
		scanf("%s", cmd);
		if (cmd[1] == 'o') {
			if (st.empty()) {
				printf("Invalid\n");
			} else {
				a = st.top(); //获得栈顶
				table[a]--; //hash的a下标元素减去1
				bucket[a/lim]--; //a所在的桶的容纳数量减去1
				printf("%d\n", a);//打印
				st.pop();//出栈
			}
		} else if (cmd[1] == 'u') {
			scanf("%d", &a);
			st.push(a);//入栈
			table[a]++;//hash的a下标元素加上1
			bucket[a/lim]++;//a所在的桶的容纳数量加上1
		} else {
			if (st.empty()) {
				printf("Invalid\n");
			} else {
				size = st.size();
				size = size & 1 ? (size + 1) / 2 : size / 2;
				int b = size / lim;
				int cur = 0; //cur表示的是当前获得rank
				int idx = 0;//枚举的桶下标
				for (idx = 0; idx < lim; idx++) {
					if (cur + bucket[idx] < size) cur += bucket[idx];//挨个加上每一个桶的数量，如果没有大于size就直接加上去
					else break;
				}
				b = idx * lim; //b表示的是在hash表内枚举到下标
				for ( ; b <= b + lim; b++) { //肯定是在这个[b, b+lim]这个区间内能完成查找
					int ff = table[b];
					if (cur + ff >= size) { //如果大于size，证明有一个后者多个元素，说明b就是我们要找的元素
						printf("%d\n", b);
						break;
					} else cur += ff; //否则加上b的数量
				}
			}
		}
	}
}

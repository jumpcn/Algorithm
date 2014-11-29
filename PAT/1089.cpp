#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], changed[N], t[N]; //分别为原始数组，和中间状态数组，和临时数组
int n;
bool isSame(int* A, int* B) { //判断是否一样
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) return false;
	}
	return true;
}

bool showArray(int *A) { //输出答案函数
	for (int i = 0; i < n; i++) {
		if (i == 0) printf("%d", A[i]);
		else printf(" %d", A[i]);
	}
	printf("\n");
}

bool insertSort() {
	bool flag = false; //判断是否到了中间状态
	for (int i = 1; i < n; i++) {

		if (isSame(t, changed)) flag = true; //如果到了中间状态就
		if (t[i] < t[i-1]) { //这里为插入排序过程
			int temp = t[i], j = i;
			while (j > 0 && temp < t[j - 1]) {
				t[j] = t[j - 1];
				j--;
			}
			t[j] = temp;
			if (flag) { //如果前面一个状态是中间状态，这里就要返回
				return true;
			}
		}
	}
	return false;
}

void  mergeSort() {
	bool flag = false;//判断是否到了中间状态

	for (int step = 2; ; step *= 2) { //这里的step是mergeSort每次处理的区间长
	    if (isSame(t, changed)) { //如果到了中间状态就
			flag = true;
		}
		for (int i = 0; i < n; i++) t[i] = origin[i]; //每次攻原始状态枚举
		if (step > n) { //这里需要特判的是当枚举到step覆盖了整个数组的时候，这个时候肯定是全部已经排序好的了
			sort(t, t + n);
			showArray(t);
			return;
		}
		for (int i = 0; i < n - step; i += step) { //按照区间来排序，直接暴力sort
			sort(t + i, t + i + step);
		}
		if (n % step != 0) { //注意处理可能区间长不是为step的整数倍的情况
			sort(t + n / step * step, t + n);
		}
		if (flag) { //如果前面一个状态是中间状态，这里就要返回
			showArray(t);
			return;
		}

	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", origin + i);
		t[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", changed + i);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		showArray(t);
	} else {
		printf("Merge Sort\n");
		mergeSort();
	}
}

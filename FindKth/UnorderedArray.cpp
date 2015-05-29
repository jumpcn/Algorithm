#include <iostream>
#include <vector>
using namespace std;
//using quicksort
//best time complexity O(n) worst O(n^2)

int findK(vector<int>& a, int l, int r, int k) {
	int left = l, right = r;
	int t = a[l];
	while (l < r) {
		while (l < r && a[r] >= t) r--;
		a[l] = a[r];
		while (l < r && a[l] <= t) l++;
		a[r] = a[l];
	}
	a[l] = t;
	if (l == k) return a[l];
	if (l > k) return findK(a, left, l - 1, k);
	return findK(a, l + 1, right, k);
}


int main() {
	int A[] = { 7, 6, 5, 4, 3, 2, 1 };
	vector<int> a(A, A + 7);
	for (int i = 0; i < 7; i++) {
		cout << findK(a, 0, a.size() - 1, i) << endl;
	}
}
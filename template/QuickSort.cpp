#include<bits/stdc++.h>

using namespace std;

template <typename T>
void qsort(T& a, int l, int r) {
    cout<< l << " " << r << endl;
    int left = l, right = r;
    int t = a[l];
    while(l < r) {
        while(l < r && a[r] >= t) r--;
        a[l] = a[r];
        while(l < r && a[r] <= t) l++;
        a[r] = a[l];
    }
    a[l] = t;
    if(left < l - 1) qsort(a, left, l - 1);
    if(l + 1 < right) qsort(a, l + 1, right);
}
int main() {
    srand(time(0));
    long long t = clock();
    vector<int> v1;
    for(int i = 0; i < 10000; i++) v1.push_back(rand());
    cout<< t << " " << clock() - t << endl;
   // qsort(v1, 0, v1.size() - 1);
}

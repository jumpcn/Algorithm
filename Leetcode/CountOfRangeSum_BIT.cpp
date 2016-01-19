#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:


    typedef long long LL;
    typedef vector<int> VI;

    void add(VI& bit, int n, int i) {
        i++;
        while(i <= n) {
            bit[i]++;
            i += (i & (-i));
        }
    }

    int sum(VI& bit, int i) {
        int ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= (i & (-i));
        }
        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        int n = nums.size();
        VI bit(n + 2, 0);
        vector<LL> vl;
        vl.push_back(0);
        LL s = 0;
        for(auto& i : nums) vl.push_back(s += i);
        sort(vl.begin(), vl.end());
        add(bit, n + 1, lower_bound(vl.begin(), vl.end(), 0) - vl.begin());
        s = 0;
        for(auto& i : nums) {
            s += i;
            ans += sum(bit, upper_bound(vl.begin(), vl.end(), s - lower) - vl.begin()) - sum(bit,lower_bound(vl.begin(), vl.end(), s-upper) - vl.begin());
            
            add(bit, n + 1, lower_bound(vl.begin(), vl.end(), s) - vl.begin());
        }
        return ans;
    }
};
/*
class Solution {
  void add(vector<int> &fenwick, int n, int x) {
    cout << "Add:" << x << endl;
    for (; x < n; x |= x+1)
      fenwick[x]++;
  }
  int getSum(vector<int> &fenwick, int x) {
      cout << "Get:" << x << endl;
    int s = 0;
    for (; x; x &= x-1)
      s += fenwick[x-1];
    return s;
  }
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    long s = 0, cnt = 0;
    vector<int> fenwick(n+1, 0);
    vector<long> scale;
    scale.push_back(0);
    for (int x: nums)
      scale.push_back(s += x);
    sort(scale.begin(), scale.end());
    s = 0;
    add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), 0) - scale.begin());
    for (int x: nums) {
      s += x;
      cnt += getSum(fenwick, upper_bound(scale.begin(), scale.end(), s-lower) - scale.begin()) -
        getSum(fenwick, lower_bound(scale.begin(), scale.end(), s-upper) - scale.begin());
      add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), s) - scale.begin());
    }
    return cnt;
  }
};
*/
int main() {
    int a[3] = {-2, 5, -1};
    vector<int> vi(a, a + 3);
    Solution s;
    
    cout  << s.countRangeSum(vi, -2, 2) << endl;
    vi.clear(); vi.push_back(0); vi.push_back(0);
    cout << s.countRangeSum(vi, 0, 0) << endl;
    vi.clear(); vi.push_back(-1); vi.push_back(1);
    cout << s.countRangeSum(vi, 0, 0) << endl;
}

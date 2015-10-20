#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;


void dfs(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if(std::distance(first, last) < 2) return;
    auto pivot = *first;
    auto mid = std::partition(first + 1, last, [pivot](int i){return pivot > i;});
    std::swap(*first, *(mid - 1));
    dfs(first, mid);
    dfs(mid, last);
}
int main() {
    int Case = 10000;
    int count = 0;
    for(int i = 0; i < Case; i++) {
        srand(time(NULL));
        int size = rand() % 100;
        vector<int> v(size);
        for_each(v.begin(), v.end(), [](int x) { x = rand(); } );
        vector<int> h(v);
        sort(h.begin(), h.end());
        dfs(v.begin(), v.end());
        count += (h != v); 
    }   
    if (count == 0) cout << "OK!" << endl;
    else cout << "ERROR!:" << count << endl;
}

#include <iostream>
#include <map> 
#include <algorithm>
using namespace std;

typedef pair<string, int> PS;
int score[1111];
string name[1111];
int main() {
    map<string, int> mp, ps;
    int n; cin >> n;
    string s;
    string ans = "";
    for(int i = 0; i < n; i++) {
        cin >> name[i] >> score[i];
        mp[name[i]] += score[i];
    }
    int Max =  max_element(mp.begin(), mp.end(),
            [](const PS&x, const PS&y) {
                return x.second < y.second;
            })->second;
    for(int i = 0; i < n; i++) {
         ps[name[i]] += score[i];
         if(ps[name[i]] >= Max && mp[name[i]] == Max) {
             cout << name[i] << endl;
             return 0;
         }
    }
}

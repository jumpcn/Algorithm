//参照http://blog.csdn.net/qwb492859377/article/details/50445450
//利用lcp快速求出lcp[a][b]来比较s[a..lcp[a][b]], s[b...lcp[a][b]]的大小关系
//dp[i][j]表示以s[0..i-1]，且最后一个字符串为s[j..i-1]的合法的切割数量
//dp[i][j]+=dp[j-1][k], max(j+1-len,1)<=k<=j-1，因为s[j-1]结尾+s[j]的肯定是符合要求的
//dp[i][j]+=dp[j-1][j-len],如果j-len>=1且以j-len开头比以j开头且长度为len数字要小
//最后用pre来快速求前缀和，加速运算

#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5005;
const int mod = 1e9 + 7;

char s[max_n];
short lcp[max_n][max_n];
int n, dp[max_n][max_n], pre[max_n][max_n];

bool check(int a, int b, int len) {
    int t = lcp[a][b];
    return t < len && s[a + t] < s[b + t];
}

void MAIN() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            if(s[i] == s[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
            else lcp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(s[j] == '0') continue;
            if(j == 1) dp[i][j] = 1;
            int len = i - j + 1;
            int l = max(j + 1 - len, 1), r = j - 1;
            if(l <= r) dp[i][j] = (pre[j-1][r] - pre[j-1][l-1]) % mod;
            if(j - len >= 1 && check(j - len, j, len)) {
                dp[i][j] = (dp[i][j] + dp[j-1][j-len]) % mod;
            }
        }
        for(int j = 1; j <= i; j++) {
            pre[i][j] = (pre[i][j-1] + dp[i][j]) % mod;
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        ans = (ans +  dp[n][i]) % mod;
    }

    printf("%d\n", (ans + mod) % mod);
}

int main() {
    MAIN();
}

//生成只有1 or -1，生成一个行向量和其他行向量的点积为0的n*n的矩阵

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < (1<<n); j++) {
            putchar(__builtin_popcount(i&j)&1 ? '*' : '+');
        }
        putchar('\n');
    }
}

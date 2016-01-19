#include <cstdio>
#include <cstring>


const int N = 1e6 + 1;

char a[N], b[N];
int main() {
    scanf("%s", a);
    scanf("%s", b);
    int i = 0, j = 0;
    while(a[i] == '0') i++;
    while(b[j] == '0') j++;
    int lenA = strlen(a + i), lenB = strlen(b + j);
    if(lenA != lenB) {
        printf(lenA > lenB ? ">" : "<");
    } else {
        int cmp = strcmp(a + i, b + j);
        if(cmp == 0) printf("=");
        else printf(cmp > 0 ? ">" : "<");
    }
}

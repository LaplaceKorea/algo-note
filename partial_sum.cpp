// https://csacademy.com/contest/archive/task/paint-the-fence/statement/


#include<bits/stdc++.h>
using namespace std;

int n, m;
int p[100005][2];
int v[100005]; // add 1 to [L, R] --> v[L]++, v[R+1]--
int w[100005]; // w[i] = v[1] + ... + v[i] = w[i-1] + v[i] : sum for index i
int c[100005];
int sc[100005];
int main() {
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &p[i][0], &p[i][1]);
        v[p[i][0]]++;
        v[p[i][1]+1]--;
    }
    
    for(int i = 1; i <= n; i++) {
        w[i] = w[i-1] + v[i];
        c[i] = w[i] == 1 ? 1 : 0;
        sc[i] = sc[i-1] + c[i];
    }
    
    int nzero = 0;
    for(int i = 1; i <= n; i++) {
        if (w[i] == 0) nzero++;
    }
    
    for(int i = 0; i < m; i++) {
        printf("%d\n", sc[p[i][1]] - sc[p[i][0]-1] + nzero);
    }
}

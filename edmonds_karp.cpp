#include<bits/stdc++.h>
using namespace std;

// https://wondy1128.tistory.com/181
int c[2005][2005];
int f[2005][2005];
int parent[2005];
int n, m;

int residual(int from, int to) {
    return c[from][to] - f[from][to];
}

int edmonds_karp(int source, int sink, int n_nodes) {
    int total = 0; // maximul flow
    
    while (1) {
        memset(parent, -1, sizeof(parent));
        queue<int> que;
        que.push(source);
        parent[source] = source;
        while (!que.empty() && parent[sink] == -1) {
            int current = que.front(); que.pop();
            for(int v = 0; v < n_nodes; v++) {
                if (residual(current, v) > 0 && parent[v] == -1) {
                    parent[v] = current;
                    que.push(v);
                }
            }
        }
        
        // if no path to sink is available
        if (parent[sink] == -1) break;
        
        // find flow from source to sink
        int flow = 1987654321;
        for(int p = sink; p != source; p = parent[p]) {
            flow = min(flow, residual(parent[p], p));
        }
        
        // reduce edge capacity
        for(int p = sink; p != source; p = parent[p]) {
            f[parent[p]][p] += flow;
            f[p][parent[p]] -= flow;
        }
        
        // update total flow
        total += flow;
    }
    
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    
    int a, b;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        for(int j = 0; j < a; j++) {
            cin >> b;
            c[i][n + b] = 1;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        c[0][i] = 1;
    }
    
    for(int i = 1; i <= m; i++) {
        c[n + i][n + m + 1] = 1;
    }
    
    int v = edmonds_karp(0, n + m + 1, n + m + 2);
    cout << v << endl;  
}

// https://csacademy.com/contest/archive/task/crossing-tree/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define MAX 100100

int n;
vector<int> v[MAX];
int d[MAX];
int visit[MAX];
int p[MAX];
int rp[MAX];

int st;
int ed;

void dfs(int node, int dist, int prev) {
    if (visit[node]) return;
    
    visit[node] = 1;
    d[node] = dist;
    p[node] = prev;
    
    for(int next: v[node]) {
        dfs(next, dist + 1, node);
    }
}

int get_diameter() {
    // run dfs from any node, calculate distances
    dfs(1, 0, 0);

    // find farthest node
    int maxdist = -1;
    int maxnode = 0;
    for(int i = 1; i <= n; i++) {
        if (d[i] > maxdist) {
            maxdist = d[i];
            maxnode = i;
        }
    }
    
    st = maxnode;

    memset(d, 0, MAX);
    memset(visit, 0, MAX);
    memset(p, 0, MAX);

    // run dfs again from the node previously found
    dfs(maxnode, 0, 0);

    // find farthest node agian
    maxdist = -1;
    maxnode = 0;
    for(int i = 1; i <= n; i++) {
        if (d[i] > maxdist) {
            maxdist = d[i];
            maxnode = i;
        }
    }
    
    ed = maxnode;

    // max distance is the diameter of the tree
    return maxdist;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int diameter = get_diameter();
}


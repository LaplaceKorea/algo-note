#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// https://github.com/kjp4155/icpc-teamnote/blob/master/src/Graph/Dinic.cpp
struct Dinic{
    struct Edge {
        int to;
        int inv;
        ll r; // residual
    };
    
    int n; // number of nodes
    vector<vector<Edge>> graph; // adjacent graph
    vector<int> level; // level graph
    vector<int> work; // pointing next edge to be used
    
    void init(int n_nodes) {
        n = n_nodes + 10;
        graph.resize(n);
        level.resize(n);
        work.resize(n);
    }
    
    void connect(int s, int e, ll capacity, ll capacity_r = 0) {
        // graph[e][graph[e].size()] will be s
        // graph[s][graph[s].size()] will be e
        Edge forward = {e, (int)graph[e].size(), capacity};
        Edge backward = {s, (int)graph[s].size(), capacity_r};
        graph[s].push_back(forward);
        graph[e].push_back(backward);
    }
    
    bool bfs(int source, int sink) {
        queue<int> que;
        fill(level.begin(), level.end(), -1);
        
        level[source] = 0;
        que.push(source);
        
        while(!que.empty()) {
            int cur = que.front(); que.pop();
            for(Edge e : graph[cur]) {
                // if level is not set, and residual is not 0
                if (level[e.to] == -1 && e.r > 0) {
                    level[e.to] = level[cur] + 1;
                    que.push(e.to);
                }
            }
        }
        
        // if path to sink exists, return true
        return level[sink] != -1;
    }
    
    ll dfs(int cur, int sink, ll flow) {
        
        // reached to sink
        if (cur == sink) return flow;
        
        // by using reference, if i increases, work[cur] also increases
        for (int &i = work[cur]; i < (int)graph[cur].size(); i++) {
            Edge &e = graph[cur][i];
            
            // update only if residual is not 0 and level is next level of current node
            if (e.r == 0 || level[e.to] != level[cur] + 1) continue;
            
            ll _flow = dfs(e.to, sink, min(flow, e.r));
            if (_flow > 0) {
                e.r -= _flow;
                graph[e.to][e.inv].r += _flow;
                return _flow;
            }
        }
        return 0;
    }
    
    ll solve(int source, int sink) {
        ll ans = 0;
        while (bfs(source, sink)) {
            fill(work.begin(), work.end(), 0);
            while (1) {
                ll flow = dfs(source, sink, 54321987654321LL);
                
                if (flow == 0) break;
                ans += flow;
            }
        }
        return ans;
    }
};


// https://www.acmicpc.net/problem/2367
int n, k, d;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> d;
    
    struct Dinic dinic;
    dinic.init(n + d);
    
    for(int i = 1; i <= d; i++) {
        int a;
        cin >> a;
        dinic.connect(n + i, n + d + 1, a);
    }
    
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            int b;
            cin >> b;
            dinic.connect(i, n + b, 1);
        }
        
        dinic.connect(0, i, k);
    }
    
    ll ans = dinic.solve(0, n + d + 1);
    
    cout << ans << endl;
}

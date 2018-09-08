// O(VE)
#include<cstdio>
#include<vector>
#include<string.h>

#define SIZE 5010

vector<int> e[SIZE];
bool check[SIZE];
int match[SIZE]'
bool dfs(int node){
    if (check[node]) return false;
    check[node] = true;
    
    for (int i = 0; i < e[node].size(); i++){
        if (match[e[node][i]] == -1 || dfs(match[e[node][i]])) {
            match[e[node][i]] = node;
            return true;
        }
    }
    
    return false;
}

int main(){
    // ...
    // e[node] ~ connectable other nodes of node
    memset(match, -1, sizeof(match));
    int cnt = 0;
    
    for(int i = 1; i <= n; i++){
        memset(check, false, sizeof(check));
        if(dfs(i)) cnt++;
    }
}

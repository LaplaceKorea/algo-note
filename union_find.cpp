#include<stdio.h>

int rnk[SIZE];
int parent[SIZE];

int init(int size){
    for(int i = 0; i < size; i++){
        rnk[i] = 0;
        parent[i] = i;
    }
}

int find(int x){
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x==y){
        return;
    }
    else{
        if(rnk[x] < rnk[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            if(rnk[x] == rnk[y]) rnk[x]++;
        }
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

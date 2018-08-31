#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int ll;

// sum finding lazy segment tree
// https://www.acmicpc.net/problem/10999

typedef struct SegTreeLazy {

    ll *tree;
    ll *lazy;
    ll INF;

    void init(ll n, ll value) {
        tree = (ll *)malloc((n * 4 + 1000) * sizeof(ll));
        lazy = (ll *)malloc((n * 4 + 1000) * sizeof(ll));
        for (int i = 1; i <= 4 * n; i++){
            tree[i] = value;
            lazy[i] = 0;
        }
        INF = value;
    }

    // [left, right]: updating range
    // [start, end]: node range
    
    void update_lazy(ll node, ll start, ll end) {
        // no lazy value in this node
        if (lazy[node] == 0) return;
        
        tree[node] += (end - start + 1) * lazy[node];
        
        // have child node
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        
        // reset lazy
        lazy[node] = 0;
    }

    void update(ll node, ll val, ll left, ll right, ll start, ll end) {
        update_lazy(node, start, end); // update lazy when node is visited
        
        // no overlap
        if  (right < start || end < left) return;
        
        // full overlap
        if (left <= start && end <= right) {
            tree[node] += (end - start + 1) * val;
            
            if (start != end) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }

        // partial overlap
        update(node * 2, val, left, right, start, (start + end) / 2);
        update(node * 2 + 1, val, left, right, (start + end) / 2 + 1, end);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }


    ll get(ll node, ll left, ll right, ll start, ll end) {
        update_lazy(node, start, end); // update lazy when node is visited
        
        // no overlap
        if (right < start || end < left) return INF;

        // full overlap
        if (left <= start && end <= right) return tree[node];

        return get(node * 2, left, right, start, (start + end) / 2) +
               get(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
    }
} SegTreeLazy;

//int main() {
//    int n, m, k;
//    SegTreeLazy tree;
//    
//    scanf("%d%d%d", &n, &m, &k);
//    
//    tree.init(n, 0);
//    for(int i = 1; i <= n; i++){
//        int a;
//        scanf("%d", &a);
//        tree.update(1, a, i, i, 1, n);
//    }
//    
//    for(int i = 0; i < k+m; i++){
//        int type, s, e, v;
//        scanf("%d", &type);
//        if (type == 1) {
//            scanf("%d%d%d", &s, &e, &v);
//            tree.update(1, v, s, e, 1, n);
//        } else if (type == 2) {
//            scanf("%d%d", &s, &e);
//            printf("%lld\n", tree.get(1, s, e, 1, n));
//        }
//    }
//}

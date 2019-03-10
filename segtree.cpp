#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int ll;

// minimum finding segment tree
typedef struct SegTree {

    ll *tree;
    ll INF;
    ll size;

    void init(ll n, ll value) {
        size = n;
        tree = (ll *)malloc((n*4 + 1000) * sizeof(ll));
        for (int i = 1; i <= 4*n; i++) tree[i] = value;
        INF = value;
    }

    // [left, right]: updating range
    // [start, end]: node range

    void _update(ll node, ll val, ll left, ll right, ll start, ll end) {
        // no overlap
        if  (right < start || end < left) return;
        
        // full overlap
        if (left <= start && end <= right) {
            tree[node] = min(tree[node], val);
            return;
        }

        // partial overlap
        _update(node * 2, val, left, right, start, (start + end) / 2);
        _update(node * 2 + 1, val, left, right, (start + end) / 2 + 1, end);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }


    ll _get(ll node, ll left, ll right, ll start, ll end) {
        // no overlap
        if (right < start || end < left) return INF;

        // full overlap
        if (left <= start && end <= right) return tree[node];

        return min(_get(node * 2, left, right, start, (start + end) / 2),
                   _get(node * 2 + 1, left, right, (start + end) / 2 + 1, end));
    }
    
    ll get(ll left, ll right) {
        return _get(1, left, right, 1, size);
    }
    
    void update(ll idx, ll val) {
        _update(1, val, idx, idx, 1, size);
    }
    
} SegTree;


//int main() {
//    SegTree tree;
//    int n, m;
//    
//    scanf("%d%d", &n ,&m);
//    tree.init(n, 2100000000);
//    
//    for (int i = 1; i <= n; i++){
//        int a;
//        scanf("%d",&a);
//        tree.update(i, a);
//    }
//    
//    for (int i = 0; i < m; i++){
//        int s, e;
//        scanf("%d%d", &s, &e);
//        printf("%d\n", tree.get(s, e));
//    }
//}

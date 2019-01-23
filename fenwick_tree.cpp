#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long int ll;

typedef struct FenwickTree {
    
    ll *tree;
    ll size;
    
    void init(ll n) {
        size = n;
        tree = (ll *)malloc((size + 1000) * sizeof(ll));
        for(int i = 0; i < size + 1000; i++) tree[i] = 0ll;
    }
    
    ll sum(ll i) {
        ll s = 0;
        while(i > 0) {
            s += tree[i];
            i -= (i & -i);
        }
        return s;
    }
    
    void update(ll i, ll v) {
        while (i <= size) {
            tree[i] += v;
            i += (i & -i);
        }
    }
    
} FenwickTree;

/*
// https://www.acmicpc.net/problem/2042
ll nums[1000005];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    FenwickTree ftree;
    ftree.init(n);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        ftree.update(i, nums[i]);
    }
    
    for(int i = 1; i <= m+k; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            ftree.update(a, b - nums[a]);
            nums[a] = b;
        } else {
            cout << ftree.sum(b) - ftree.sum(a-1) << '\n';
        }
    }
}
*/

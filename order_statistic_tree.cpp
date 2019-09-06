#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

// FenwickTree based Order Statistic Tree
typedef struct OrderStatisticTree {
  ll *tree;
  ll size;

  void init(ll n) {
    size = n;
    tree = (ll *)malloc((size + 1000) * sizeof(ll));
    for (int i = 0; i < size + 1000; i++) tree[i] = 0ll;
  }

  ll sum(ll i) {
    ll s = 0;
    while (i > 0) {
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

  void insertElement(ll i) { update(i, 1); }

  void deleteElement(ll i) { update(i, -1); }

  ll findKth(ll k) {
    ll s = 0;
    ll e = size;
    while (s < e) {
      ll mid = (s + e) / 2;
      if (k <= sum(mid))
        e = mid;
      else
        s = mid + 1;
    }

    return s;
  }

  ll rank(ll v) { return sum(v); }

} OrderStatisticTree;

/*
// https://csacademy.com/contest/archive/task/independent-rectangles/
ll n;
vector<pll> pts;

bool comp(pll p1, pll p2) {
  if (p1.first != p2.first)
    return p1.first > p2.first;  // x descending
  else
    return p1.second < p2.second;  // y ascending
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    pts.push_back(pll(x, y));
  }

  sort(pts.begin(), pts.end(), comp);

  OrderStatisticTree tree;
  tree.init(1e6);

  ll ans = 0;
  for (int i = 0; i < pts.size(); i++) {
    pll p = pts[i];
    // cout << p.first << " " << p.second << endl;
    // ll x = p.first;
    ll y = p.second;
    tree.insertElement(y);

    if (tree.rank(1e6) - tree.rank(y) == 0) {
      // cout << "[*] " << p.first << " " << p.second << endl;
      ans++;
    }
  }

  cout << ans << '\n';
}
*/
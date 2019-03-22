#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll MAX_E = 200001;

struct uf_tree {
  vector<ll> par, sizes;
  uf_tree(ll n) : par(n), sizes(n, 1) {
    for (ll i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  ll find(ll x) {
    if (x == par[x]) {
      return x;
    }
    return par[x] = find(par[x]);
  }
  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (sizes[x] < sizes[y]) {
      swap(x, y);
    }
    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(ll x, ll y) { return find(x) == find(y); }
  ll size(ll x) { return sizes[find(x)]; }
};

struct edge {
  ll u, v, cost;
};
bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
ll V, E;

ll kruskal() {
  sort(es, es + E, comp);
  uf_tree uf(V);
  ll res = 0;
  for (ll i = 0; i < E; i++) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

ll N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  V = N;
  E = 2 * (N - 1);
  vector<pair<long, long>> x(N), y(N);
  for (int i = 0; i < N; i++) {
    long xi, yi;
    cin >> xi >> yi;
    x[i] = make_pair(xi, i);
    y[i] = make_pair(yi, i);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 1; i < N; i++) {
    es[i - 1] =
        edge{x[i - 1].second, x[i].second, abs(x[i].first - x[i - 1].first)};
  }
  for (int i = 1; i < N; i++) {
    es[i - 2 + N] =
        edge{y[i - 1].second, y[i].second, abs(y[i].first - y[i - 1].first)};
  }

  cout << kruskal() << endl;
  return 0;
}
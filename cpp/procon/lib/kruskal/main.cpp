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

struct uf_tree {
  vector<int> par, sizes;
  uf_tree(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (x == par[x]) {
      return x;
    }
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
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
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return sizes[find(x)]; }
};

const int MAX_E = 100001;

struct edge {
  int u, v, cost;
};
bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
int V, E;

// 最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
// を求めるアルゴリズム
int kruskal() {
  sort(es, es + E, comp);
  uf_tree uf(V);
  int res = 0;
  for (int i = 0; i < E; i++) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int si, ti, wi;
    cin >> si >> ti >> wi;
    es[i] = edge{si, ti, wi};
  }

  cout << kruskal() << endl;
  return 0;
}
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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

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

int N, M;
vector<int> p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  p.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> p[i];
  }
  uf_tree uf(N + 1);

  for (int i = 1; i <= M; i++) {
    int xi, yi;
    cin >> xi >> yi;
    uf.unite(p[xi], p[yi]);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (uf.same(i, p[i])) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
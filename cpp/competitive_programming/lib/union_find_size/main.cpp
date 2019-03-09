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

// ref. https://kira924age.github.io/Algorithm/data_structure/union_find.html
//
// 親がsizeのマイナス値を持つ実装もある:
//   https://ei1333.github.io/luzhiled/snippets/structure/union-find.html

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 10;
  // cin >> n;
  uf_tree uf(n);

  uf.unite(2, 3);
  uf.unite(2, 4);

  if (uf.same(3, 4)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  if (uf.same(2, 5)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  cout << uf.size(3) << endl;
  return 0;
}
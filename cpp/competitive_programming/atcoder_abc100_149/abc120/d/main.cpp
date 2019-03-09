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
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
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
vector<int> A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  A.resize(M);
  B.resize(M);
  for (int i = 0; i < M; i++) {
    int ai, bi;
    cin >> ai >> bi;
    A[i] = ai - 1;
    B[i] = bi - 1;
  }
  uf_tree uf(N);

  vector<long> ans_vec(M, 0);
  ans_vec[M - 1] = (long)N * (long)(N - 1) / 2L;

  for (int i = M - 1; i > 0; i--) {
    long a_par = uf.find(A[i]);
    long b_par = uf.find(B[i]);

    if (a_par == b_par) {
      ans_vec[i - 1] = ans_vec[i];
    } else {
      long an = uf.size(a_par);
      long bn = uf.size(b_par);
      ans_vec[i - 1] = ans_vec[i] - (long)an * (long)bn;
    }

    uf.unite(A[i], B[i]);
  }

  for (auto &e : ans_vec) {
    cout << e << endl;
  }

  return 0;
}
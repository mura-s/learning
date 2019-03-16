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

const int MAX_N = 400000;

// 親
int par[MAX_N];
// 木の深さ
int depth[MAX_N];

void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    depth[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }

  if (depth[x] < depth[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (depth[x] == depth[y]) {
      depth[x]++;
    }
  }
}

bool same(int x, int y) { return find(x) == find(y); }

int N, K, L;
map<pair<int, int>, int> mp;
vector<int> a, b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> L;
  init(2 * N);
  for (int i = 0; i < K; i++) {
    int pi, qi;
    cin >> pi >> qi;
    unite(pi - 1, qi - 1);
  }

  for (int i = 0; i < L; i++) {
    int ri, si;
    cin >> ri >> si;
    unite(ri + N - 1, si + N - 1);
  }

  a.resize(N);
  b.resize(N);
  for (int i = 0; i < N; i++) {
    a[i] = find(i);
    b[i] = find(i + N);
    mp[make_pair(a[i], b[i])]++;
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << mp[make_pair(a[i], b[i])];
  }
  cout << endl;
  return 0;
}
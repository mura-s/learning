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

// ref. 蟻本

const int MAX_N = 101;

// 親
int par[MAX_N];
// 木の深さ (rank)
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 10;
  // cin >> n;
  init(n);

  unite(2, 3);
  unite(2, 4);

  if (same(3, 4)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  if (same(2, 5)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
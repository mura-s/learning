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

const int MAX_N = 1000;

// 与えられるグラフは連結グラフであるとする。

int N, M;
vector<int> g[MAX_N];

int color[MAX_N];

// v: vertex.
// c: color. 1 or -1.
bool dfs(int v, int c) {
  color[v] = c;

  for (int i = 0; i < g[v].size(); i++) {
    if (color[g[v][i]] == c) {
      return false;
    }
    if (color[g[v][i]] == 0 && !dfs(g[v][i], -c)) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  if (dfs(0, 1)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;
// const int INF = 2000000000;

const int MAX_V = 200001;

struct edge {
  int to, cost;
};
vector<edge> g[MAX_V];

pair<int, int> dfs(int idx, int parent) {
  pair<int, int> ret(0, idx);
  for (auto &e : g[idx]) {
    if (e.to == parent) {
      continue;
    }
    auto cost = dfs(e.to, idx);
    cost.first += e.cost;
    if (ret.first < cost.first) {
      ret = cost;
    }
  }
  return ret;
}

int tree_diameter() {
  auto p = dfs(0, -1);
  auto q = dfs(p.second, -1);
  return q.first;
}

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(edge{b, 1});
    g[b].push_back(edge{a, 1});
  }

  int d = tree_diameter();
  if (d % 3 == 1) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}
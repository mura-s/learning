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

// 重み付き木の直径を求める.
// (重みが与えられていない場合は, 全ての重みを1とする.)
//
// 頂点数をNとして、計算量は O(N).

const int MAX_V = 100001;

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

// verify:
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    g[s].push_back(edge{t, w});
    g[t].push_back(edge{s, w});
  }

  int ans = tree_diameter();
  cout << ans << endl;
  return 0;
}
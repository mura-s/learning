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

const int MAX_V = 10001;

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは重み, secondは頂点の番号

int V, E;
vector<edge> G[MAX_V];

// 最小全域木 (全域木のうち、その辺群の重みの総和が最小になる木)
// を求めるアルゴリズム
// https://ei1333.github.io/luzhiled/snippets/graph/prim.html
int prim() {
  int ans = 0;
  vector<bool> used(V, false);
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P{0, 0});
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int v = p.second;
    if (used[v]) {
      continue;
    }
    used[v] = true;
    ans += p.first;

    for (int i = 0; i < G[v].size(); i++) {
      que.push(P{G[v][i].cost, G[v][i].to});
    }
  }

  return ans;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int si, ti, wi;
    cin >> si >> ti >> wi;
    G[si].push_back(edge{ti, wi});
    G[ti].push_back(edge{si, wi});
  }

  cout << prim() << endl;
  return 0;
}
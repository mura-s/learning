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

const int INF = 2000000000;
const int MAX_V = 100001;

struct edge {
  int to, cost;
};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

int V, E;
vector<edge> G[MAX_V];
int d[MAX_V];
int prev_path[MAX_V]; // prev_path[i]の流入元の点

// 負辺のない単一始点全点間最短路を求めるアルゴリズム。
// 蟻本参照
void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  fill(prev_path, prev_path + V, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        prev_path[e.to] = v;
      }
    }
  }
}

// 経路復元
vector<int> get_path(int e) {
  vector<int> path;
  for (; e != -1; e = prev_path[e]) {
    path.push_back(e);
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r;
  cin >> V >> E >> r;
  for (int i = 0; i < E; i++) {
    int si, ti, di;
    cin >> si >> ti >> di;
    G[si].push_back(edge{ti, di});
  }

  dijkstra(r);
  cout << d[6] << endl;

  vector<int> path = get_path(6);
  for (int i = 0; i < path.size(); i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << path[i];
  }
  cout << endl;
  return 0;
}
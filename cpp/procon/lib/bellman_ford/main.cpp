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

const int MAX_V = 100;
const int MAX_E = 100;

struct edge {
  int from, to, cost;
};

// 辺
edge es[MAX_E];
// 最短距離
int d[MAX_V];
int V, E;

// ref. https://ei1333.github.io/luzhiled/snippets/graph/bellman-ford.html
// - falseを返す場合は負の経路が存在.
// - d[i]がINFの場合は経路が存在しない.
bool bellman_ford(int s) {
  fill(d, d + V, INF);
  d[s] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if (d[e.from] == INF) {
        continue;
      }
      d[e.to] = min(d[e.to], d[e.from] + e.cost);
    }
  }

  for (int j = 0; j < E; j++) {
    edge e = es[j];
    if (d[e.from] == INF) {
      continue;
    }
    if (d[e.from] + e.cost < d[e.to]) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // initialize
  V = 7, E = 20;
  // A = 0, B = 1, ..., G = 6
  es[0] = edge{0, 1, 2};
  es[1] = edge{1, 0, 2};
  es[2] = edge{0, 2, 5};
  es[3] = edge{2, 0, 5};
  es[4] = edge{1, 2, 4};
  es[5] = edge{2, 1, 4};
  es[6] = edge{1, 3, 6};
  es[7] = edge{3, 1, 6};
  es[8] = edge{1, 4, 10};
  es[9] = edge{4, 1, 10};
  es[10] = edge{2, 3, 2};
  es[11] = edge{3, 2, 2};
  es[12] = edge{3, 5, 1};
  es[13] = edge{5, 3, 1};
  es[14] = edge{4, 5, 3};
  es[15] = edge{5, 4, 3};
  es[16] = edge{4, 6, 5};
  es[17] = edge{6, 4, 5};
  es[18] = edge{5, 6, 9};
  es[19] = edge{6, 5, 9};

  bool flag = bellman_ford(0);
  if (!flag) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  if (d[6] == INF) {
    cout << "INF" << endl;
  }
  cout << d[6] << endl;
  return 0;
}
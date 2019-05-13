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

const int MAX_V = 101;

int d[MAX_V][MAX_V];
int V, E;

// 隣接行列で表されるグラフの全点間最短路を求めるアルゴリズム。
// 負辺があっても動作する。負閉路が存在する場合はそれも検出する。
// https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html
void warshall_floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (d[i][k] == INF || d[k][j] == INF) {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < E; i++) {
    int si, ti, di;
    cin >> si >> ti >> di;
    d[si][ti] = di;
  }

  warshall_floyd();
  for (int i = 0; i < V; i++) {
    if (d[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (j != 0) {
        cout << " ";
      }
      if (d[i][j] == INF) {
        cout << "INF";
      } else {
        cout << d[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
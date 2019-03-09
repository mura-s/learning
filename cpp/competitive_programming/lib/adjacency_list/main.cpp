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

// グラフの隣接リストでの表現。 (蟻本参照)
// 辺があるかの判定: 最悪|V|
// メモリ: |V| + |E|

const int MAX_V = 3;
vector<int> g[MAX_V];
/*
辺に属性がある場合
struct edge { int to, cost; };
vector<edge> g[MAX_V];
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 有向グラフ
  g[0].push_back(1);
  g[0].push_back(2);
  g[1].push_back(2);

  for (int i = 0; i < MAX_V; i++) {
    for (auto &e : g[i]) {
      cout << i << "->" << e << endl;
    }
  }

  return 0;
}
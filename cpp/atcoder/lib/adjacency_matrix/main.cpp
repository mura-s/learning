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

// グラフの隣接行列での表現。 (蟻本参照)
// 辺があるかの判定: 定数時間
// メモリ: |V|^2
//
// 無向グラフの場合、 g[i][j] == g[j][i] となるように設定する。
// 有向グラフの場合、 i->jに向かう辺があるなら、g[i][j] == 1 となる。

const int MAX_V = 5;
int g[MAX_V][MAX_V];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 無向グラフ
  g[0][1] = g[1][0] = 1;
  g[0][3] = g[3][0] = 1;
  g[1][2] = g[2][1] = 1;
  g[1][3] = g[3][1] = 1;
  g[2][3] = g[3][2] = 1;
  g[3][4] = g[4][3] = 1;

  for (int i = 0; i < MAX_V; i++) {
    for (int j = 0; j < MAX_V; j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
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
const int INF = 2000000000;

int H, W;
int g[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  queue<pair<int, int>> q;
  fill(g[0], g[1001], INF);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        q.push(make_pair(i, j));
        g[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int h = p.first, w = p.second;
    if (h - 1 >= 0 && g[h - 1][w] == INF) {
      g[h - 1][w] = g[h][w] + 1;
      q.push(make_pair(h - 1, w));
    }
    if (w - 1 >= 0 && g[h][w - 1] == INF) {
      g[h][w - 1] = g[h][w] + 1;
      q.push(make_pair(h, w - 1));
    }
    if (h + 1 < H && g[h + 1][w] == INF) {
      g[h + 1][w] = g[h][w] + 1;
      q.push(make_pair(h + 1, w));
    }
    if (w + 1 < W && g[h][w + 1] == INF) {
      g[h][w + 1] = g[h][w] + 1;
      q.push(make_pair(h, w + 1));
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, g[i][j]);
    }
  }

  cout << ans << endl;
  return 0;
}
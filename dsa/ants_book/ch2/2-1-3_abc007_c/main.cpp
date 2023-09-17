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

const int INF = 1000000000;

int ys[4] = {-1, 0, 1, 0};
int xs[4] = {0, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int R, C;
  int sy, sx, gy, gx;
  char maze[51][51];
  cin >> R >> C;
  cin >> sy >> sx >> gy >> gx;
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cin >> maze[i][j];
    }
  }

  int d[R + 1][C + 1];
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      d[i][j] = INF;
    }
  }

  d[sy][sx] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(sy, sx));
  while (q.size() > 0) {
    auto p = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int new_y = p.first + ys[i];
      int new_x = p.second + xs[i];
      if (maze[new_y][new_x] == '.' && d[new_y][new_x] == INF) {
        d[new_y][new_x] = d[p.first][p.second] + 1;
        q.push(make_pair(new_y, new_x));
      }
    }
  }

  cout << d[gy][gx] << endl;
  return 0;
}
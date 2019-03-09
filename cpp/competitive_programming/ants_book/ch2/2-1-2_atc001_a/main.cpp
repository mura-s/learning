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

int H, W;
char c[501][501];
vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(0, -1),
                                     make_pair(1, 0), make_pair(0, 1)};

bool dfs(int h, int w) {
  if (c[h][w] == 'g') {
    return true;
  }

  c[h][w] = '#';

  for (auto &e : directions) {
    int new_h = h + e.first, new_w = w + e.second;
    if (0 <= new_h && new_h < H && 0 <= new_w && new_w < W &&
        c[new_h][new_w] != '#') {
      if (dfs(new_h, new_w)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  int start_h, start_w;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> c[i][j];
      if (c[i][j] == 's') {
        start_h = i, start_w = j;
      }
    }
  }

  if (dfs(start_h, start_w)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
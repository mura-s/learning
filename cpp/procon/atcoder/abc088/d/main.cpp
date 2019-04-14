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
// const int INF = 2000000000;
// const ll MOD = 1000000007;

struct Pos {
  int h, w;
  int len;
};

int H, W;
char S[51][51];
int num_black;
int min_len;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S[i][j];
      if (S[i][j] == '#') {
        num_black++;
      }
    }
  }

  bool goal = false;
  queue<Pos> q;
  q.push(Pos{0, 0, 1});
  while (!q.empty()) {
    Pos p = q.front();
    q.pop();
    if (p.h == H - 1 && p.w == W - 1) {
      goal = true;
      min_len = p.len;
      break;
    }

    // up
    if (p.h - 1 >= 0 && S[p.h - 1][p.w] != '#') {
      S[p.h - 1][p.w] = '#';
      q.push(Pos{p.h - 1, p.w, p.len + 1});
    }
    // down
    if (p.h + 1 < H && S[p.h + 1][p.w] != '#') {
      S[p.h + 1][p.w] = '#';
      q.push(Pos{p.h + 1, p.w, p.len + 1});
    }
    // left
    if (p.w - 1 >= 0 && S[p.h][p.w - 1] != '#') {
      S[p.h][p.w - 1] = '#';
      q.push(Pos{p.h, p.w - 1, p.len + 1});
    }
    // right
    if (p.w + 1 < W && S[p.h][p.w + 1] != '#') {
      S[p.h][p.w + 1] = '#';
      q.push(Pos{p.h, p.w + 1, p.len + 1});
    }
  }

  if (goal) {
    cout << H * W - num_black - min_len << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
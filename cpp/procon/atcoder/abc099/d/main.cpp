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
// const long MOD = 1000000007;

int N, C;
int D[31][31];
int t[3][31];

int calc(int a, int b, int c) {
  int value = 0;
  for (int i = 1; i <= C; i++) {
    value += t[0][i] * D[i][a];
  }
  for (int i = 1; i <= C; i++) {
    value += t[1][i] * D[i][b];
  }
  for (int i = 1; i <= C; i++) {
    value += t[2][i] * D[i][c];
  }
  return value;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> C;
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> D[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int c;
      cin >> c;
      t[(i + j) % 3][c]++;
    }
  }

  int ans = INT_MAX;
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= C; j++) {
      if (i == j) {
        continue;
      }
      for (int k = 1; k <= C; k++) {
        if (i == k || j == k) {
          continue;
        }

        ans = min(ans, calc(i, j, k));
      }
    }
  }

  cout << ans << endl;
  return 0;
}
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
// const int INF = 2000000000;
const ll MOD = 1000000007;

int N;
ll dp[101][4][4][4];

bool check3(int i, int j, int k) {
  if (i == 0 && j == 2 && k == 1) {
    return false;
  }
  if (i == 0 && j == 1 && k == 2) {
    return false;
  }
  if (i == 2 && j == 0 && k == 1) {
    return false;
  }
  return true;
}

bool check4(int i, int j, int k, int l) {
  if (!check3(j, k, l)) {
    return false;
  }
  if (i == 0 && j == 2 && l == 1) {
    return false;
  }
  if (i == 0 && k == 2 && l == 1) {
    return false;
  }
  return true;
}

// 0 = A, 1 = C, 2 = G, 3 = T
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  fill(dp[0][0][0], dp[101][0][0], 0);

  int n = 3;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (check3(i, j, k)) {
          dp[n][i][j][k] = 1;
        } else {
          dp[n][i][j][k] = 0;
        }
      }
    }
  }

  for (int n = 4; n <= N; n++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          for (int l = 0; l < 4; l++) {
            if (check4(i, j, k, l)) {
              dp[n][j][k][l] = (dp[n][j][k][l] + dp[n - 1][i][j][k]) % MOD;
            }
          }
        }
      }
    }
  }

  long ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        ans = (ans + dp[N][i][j][k]) % MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
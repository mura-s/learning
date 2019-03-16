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

// 蟻本の重複組合せの問題。
// 解説: https://everydaytekitou.hatenablog.com/entry/2017/03/17/232149

// dp[i+1][j]: i番目までの品物からj個選ぶ組み合わせの総数
int dp[1001][1001];

int n, m, M;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> M;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // 1つも選ばない場合
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j - 1 - a[i] >= 0) {
        // +Mは負になるケースを考慮
        dp[i + 1][j] =
            (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}
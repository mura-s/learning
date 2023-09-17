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

// 蟻本の分割数の問題。
// 説明は http://techtipshoge.blogspot.com/2011/01/blog-post_28.html
// がわかりやすい。

// dp[i][j]: 整数jをi個以下に分割するパターン数
// dp[max_m + 1][max_n + 1]
int dp[10001][1001];

int n, m, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> M;
  dp[0][0] = 1;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[m][n] << endl;
  return 0;
}
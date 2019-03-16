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
const int INF = 2 * pow(10, 9);
int dp[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> as(N), a_sums(N);
  for (int i = 0; i < N; i++) {
    cin >> as[i];
    a_sums[i] = i == 0 ? as[i] : a_sums[i - 1] + as[i];
  }

  if (K == a_sums[N - 1]) {
    cout << 1 << endl;
    return 0;
  }

  fill(dp[0], dp[2001], INF);
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }

  for (int i = 0; i < N; i++) {
    int b = as[0] == 1 && i >= 2 ? 1 : 0;
    for (int j = 1; j <= i + 1 - b; j++) {
      if (j == 1) {
        dp[i + 1][j] = 1;
      } else {
        double prev_wr = (double)dp[i][j - 1] / a_sums[i - 1];
        int win = (int)(prev_wr * a_sums[i]);
        int ceiled_win = (int)ceil(prev_wr * a_sums[i]);
        if (win == ceiled_win) {
          ceiled_win++;
        }
        dp[i + 1][j] = min(dp[i][j], ceiled_win);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    if (dp[N][i] <= K) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
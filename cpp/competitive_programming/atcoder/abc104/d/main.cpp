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

const long MOD = 1000000007;
long dp[100001][4];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  dp[0][0] = 1;
  for (int i = 0; i < S.size(); ++i) {
    char c = S[i];
    // 0
    if (c == '?') {
      dp[i + 1][0] = dp[i][0] * 3 % MOD;
    } else {
      dp[i + 1][0] = dp[i][0] % MOD;
    }

    // 1
    if (c == '?') {
      dp[i + 1][1] = (dp[i][0] + dp[i][1] * 3) % MOD;
    } else if (c == 'A') {
      dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
    } else {
      dp[i + 1][1] = dp[i][1] % MOD;
    }

    // 2
    if (c == '?') {
      dp[i + 1][2] = (dp[i][1] + dp[i][2] * 3) % MOD;
    } else if (c == 'B') {
      dp[i + 1][2] = (dp[i][1] + dp[i][2]) % MOD;
    } else {
      dp[i + 1][2] = dp[i][2] % MOD;
    }

    // 3
    if (c == '?') {
      dp[i + 1][3] = (dp[i][2] + dp[i][3] * 3) % MOD;
    } else if (c == 'C') {
      dp[i + 1][3] = (dp[i][2] + dp[i][3]) % MOD;
    } else {
      dp[i + 1][3] = dp[i][3] % MOD;
    }
  }

  cout << dp[S.size()][3] << endl;
  return 0;
}
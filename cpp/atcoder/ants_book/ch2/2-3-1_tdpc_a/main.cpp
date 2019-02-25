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

int N;
vector<int> ps;
bool dp[101][10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  ps.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> ps[i];
  }
  fill(dp[0], dp[101], false);
  dp[0][0] = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (j - ps[i] >= 0) {
        dp[i + 1][j] = dp[i][j] || dp[i][j - ps[i]];
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 10000; i++) {
    if (dp[N][i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
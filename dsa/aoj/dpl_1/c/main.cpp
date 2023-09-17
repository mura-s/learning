#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = (1 << 30) - 1;
// const ll L_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int N, W;
vector<int> v, w;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> W;
  v.resize(N);
  w.resize(N);
  for (int i = 0; i < N; i++) {
    int vi, wi;
    cin >> vi >> wi;
    v[i] = vi;
    w[i] = wi;
  }

  int dp[W + 1];
  fill(dp, dp + W + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (dp[j] != -1 && j + w[i] <= W) {
        dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= W; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}

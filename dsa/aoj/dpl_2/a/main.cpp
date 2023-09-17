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
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int V, E;
vector<vector<int>> d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E;
  d.resize(V, vector<int>(V, INF));
  rep(i, E) {
    int si, ti, di;
    cin >> si >> ti >> di;
    d[si][ti] = di;
  }

  int dp[1 << V][V];
  rep(i, 1 << V) { fill(dp[i], dp[i] + V, INF); }
  dp[0][0] = 0;

  rep(i, 1 << V) {
    rep(s, V) {
      rep(t, V) {
        if (s == t) {
          continue;
        }
        if ((i & (1 << t)) > 0) {
          continue;
        }
        if (d[s][t] == INF) {
          continue;
        }
        dp[i | (1 << t)][t] = min(dp[i | (1 << t)][t], dp[i][s] + d[s][t]);
      }
    }
  }

  if (dp[(1 << V) - 1][0] == INF) {
    cout << -1 << endl;
  } else {
    cout << dp[(1 << V) - 1][0] << endl;
  }
  return 0;
}

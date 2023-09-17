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

int n, m;
vector<int> c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  c.resize(m);
  rep(i, m) { cin >> c[i]; }
  int dp[n + 1];
  fill(dp, dp + n + 1, INF);
  dp[0] = 0;

  rep(i, m) {
    rep(j, n + 1) {
      if (dp[i] != INF && j + c[i] <= n) {
        dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
      }
    }
  }

  cout << dp[n] << endl;
  return 0;
}

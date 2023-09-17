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

int q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> q;
  rep(i, q) {
    string x, y;
    cin >> x >> y;
    int dp[y.size() + 1][x.size() + 1];
    rep(j, y.size() + 1) {
      fill(dp[j], dp[j] + x.size() + 1, INF);
      dp[j][0] = 0;
    }
    fill(dp[0], dp[0] + x.size() + 1, 0);

    for (int j = 1; j <= y.size(); j++) {
      for (int k = 1; k <= x.size(); k++) {
        if (y[j - 1] == x[k - 1]) {
          dp[j][k] = dp[j - 1][k - 1] + 1;
        } else {
          dp[j][k] = max(dp[j][k - 1], dp[j - 1][k]);
        }
      }
    }

    cout << dp[y.size()][x.size()] << endl;
  }

  return 0;
}

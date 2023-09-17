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

// const int INF = (1 << 30) - 1;
// const ll LL_INF = (1LL << 62) - 1;
// const ll MOD = 1e9 + 7;
// const double PI = M_PI;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    vector<int> w(N);
    rep(i, N) { cin >> w[i]; }
    int dp[N][N + 1]; // [l, r)
    rep(i, N) { fill(dp[i], dp[i] + N + 1, 0); }

    for (int W = 2; W <= N; W++) {
      for (int l = 0; l < N; l++) {
        int r = l + W;
        if (r > N) {
          continue;
        }
        if (dp[l + 1][r - 1] == W - 2 && abs(w[l] - w[r - 1]) <= 1) {
          dp[l][r] = dp[l + 1][r - 1] + 2;
        }
        for (int k = l + 1; k < r; k++) {
          dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r]);
        }
      }
    }

    cout << dp[0][N] << endl;
  }
  return 0;
}

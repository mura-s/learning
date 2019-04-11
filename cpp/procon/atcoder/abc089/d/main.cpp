#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const int INF = 2000000000;
// const ll MOD = 1000000007;

int H, W, D;
int Q;

int magic(int i, int j, int x, int y) { return abs(x - i) + abs(y - j); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> D;
  unordered_map<int, pair<int, int>> a_map;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      int ai;
      cin >> ai;
      a_map[ai] = make_pair(i, j);
    }
  }
  cin >> Q;

  int dp[90001];
  fill(dp, dp + 90001, 0);
  for (int i = D + 1; i <= H * W; i++) {
    dp[i] = dp[i - D] + magic(a_map[i - D].first, a_map[i - D].second,
                              a_map[i].first, a_map[i].second);
  }

  while (Q--) {
    int L, R;
    cin >> L >> R;
    cout << dp[R] - dp[L] << endl;
  }

  return 0;
}

#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;
// const int INF = 2000000000;

int N;
vector<int> P;
unordered_map<int, int> mp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  P.resize(N + 1);
  // 1-indexed
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    mp[P[i]] = i;
  }

  vector<int> dp(N + 1, 0);
  int prev_pos = 0;
  for (int i = 1; i <= N; i++) {
    int pos = mp[i];
    if (prev_pos < pos) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
    prev_pos = pos;
  }

  int max_len = 0;
  for (int i = 1; i <= N; i++) {
    max_len = max(max_len, dp[i]);
  }

  int ans = N - max_len;
  cout << ans << endl;
  return 0;
}